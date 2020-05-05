// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <mylibrary/tile.h>
#include <mylibrary/utils.h>

#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/Color.h>
#include <cinder/Text.h>
#include <cinder/Rect.h>
#include <vector>


namespace myapp {

using cinder::app::KeyEvent;
using cinder::app::MouseEvent;

const size_t kLimit = 3;
const char kDbPath[] = "game.db";
const char kSoundPath[] = "win.mp3";
#if defined(CINDER_LINUX)
const char kNormalFont[] = "Arial Unicode MS";
#else
const char kNormalFont[] = "Arial";
#endif

MyApp::MyApp()
  : leaderboard_{cinder::app::getAssetPath(kDbPath).string()},
    state_{GameState::kLevelSelect},
    level_{0},
    score_{0},
    time_ended_{0} {}

void MyApp::setup() {
  cinder::audio::SourceFileRef music_file =
      cinder::audio::load(cinder::app::loadAsset(kSoundPath));
  win_sound_ = cinder::audio::Voice::create(music_file);
}

void MyApp::update() {
  if (state_ == GameState::kGameStart) {
    board_.SetSize(level_);
    std::vector<cinder::Color> colors = utils::GetRandomColors(4);
    board_.SetColors(colors[0], colors[1],colors[2], colors[3]);
    board_.Shuffle();
    state_ = GameState::kPlaying;
  }

  if (state_ == GameState::kGameEnded) {
    if (top_scores_.empty()) {
      leaderboard_.AddScoreToLeaderBoard(score_, level_, utils::GetDate());
      top_scores_ = leaderboard_.RetrieveHighScores(kLimit, level_);
    }
    // Display leaderboard after sound effect finishes
    if (std::time(nullptr) - time_ended_ > 2) {
      state_ = GameState::kLeaderboard;
    }
  }
}

void PrintText(const std::string& text, const cinder::Color& color,
               const cinder::ivec2& size,
               const cinder::vec2& loc) {
  // From the snake assignment
  cinder::gl::color(color);

  auto box = cinder::TextBox()
      .alignment(cinder::TextBox::CENTER)
      .font(cinder::Font(kNormalFont, 50))
      .size(size)
      .color(color)
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::draw() {
  if (state_ == GameState::kLevelSelect) {
    DrawMenu();
  }
  if (state_ == GameState::kGameStart) {
    cinder::gl::clear();
  }
  if (state_ == GameState::kPlaying || state_ == GameState::kGameEnded) {
    DrawBoard();
  }
  if (state_ == GameState::kLeaderboard) {
    DrawBoard();
    DrawTopScores();
  }
}

void MyApp::DrawMenu() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const cinder::ColorA white = cinder::Color::white();
  const cinder::ColorA gray = cinder::Color::gray(0.75);

  const cinder::Color l1_color = (level_ == 1) ? gray : white;
  const cinder::Color l2_color = (level_ == 2) ? gray : white;
  const cinder::Color l3_color = (level_ == 3) ? gray : white;

  PrintText("1: easy", l1_color, size,{center.x, center.y - 100});
  PrintText("2: medium", l2_color, size, center);
  PrintText("3: hard", l3_color, size,{center.x, center.y + 100});
}

void MyApp::DrawBoard() {
  int tile_width = getWindowWidth() / board_.GetSize();
  int tile_height = getWindowHeight() / board_.GetSize();
  // Drawing each tile at its current position
  for (int row = 0; row < board_.GetSize(); row++) {
    for (int col = 0; col < board_.GetSize(); col++) {
      game::Tile current_tile = board_.GetTileAt(row, col);
      cinder::gl::color(current_tile.GetColor());
      cinder::gl::drawSolidRect(cinder::Rectf(tile_width * col,
                                      tile_height * row,
                                      tile_width * col + tile_width,
                                      tile_height * row + tile_height));
    }
  }
}

void MyApp::keyDown(KeyEvent event) {
  if (state_ == GameState::kLevelSelect) {
    if (event.getChar() >= '1' && event.getChar() <= '3') {
      level_ = event.getChar() - '0';
    }

    if (event.getCode() == KeyEvent::KEY_s && level_ != 0) {
      state_ = GameState::kGameStart;
    }
  }
}

void MyApp::mouseDown(MouseEvent event) {
  if (state_ == GameState::kPlaying) {
    int tile_width = getWindowWidth() / board_.GetSize();
    int tile_height = getWindowHeight() / board_.GetSize();

    int row = event.getY() / tile_height;
    int col = event.getX() / tile_width;
    board_.Select(row, col);

    if (board_.NumSelected() == 2) {
      board_.Swap();
      score_++;

      if (board_.IsBoardSolved()) {
        time_ended_ = std::time(nullptr);
        win_sound_->start();
        state_ = GameState::kGameEnded;
      }
    }
  }
}

void MyApp::DrawTopScores() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const cinder::Color black = cinder::Color::black();

  PrintText("you won!", black, size, {center.x, center.y - 300});
  PrintText("your score: " + std::to_string(score_), black, size,
      {center.x, center.y - 200});
  int average = leaderboard_.GetAverageScore(level_);
  PrintText("average score: " + std::to_string(average), black, size,
      {center.x, center.y - 100});

  PrintText("top scores", black, size, center);
  int row = 1;
  for (const std::string& score : top_scores_) {
    PrintText(score, black, size, {center.x, center.y + 100 * row});
    row++;
  }
}

}  // namespace myapp
