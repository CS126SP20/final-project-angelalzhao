// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"


#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/Color.h>
#include <cinder/Text.h>


namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp()
  : leaderboard_{"game.db"},
    state_{GameState::kLevelSelect},
    level_{0} {}

void MyApp::setup() {

}

void MyApp::update() { }

void MyApp::draw() {
  if (state_ == GameState::kLevelSelect) {
    DrawMenu();
  }
}

void PrintText(const std::string& text, const cinder::Color& color,
               const cinder::ivec2& size,
               const cinder::vec2& loc) {
  // From the snake assignment
  cinder::gl::color(color);

  auto box = cinder::TextBox()
      .alignment(cinder::TextBox::CENTER)
      .font(cinder::Font("Arial", 50))
      .size(size)
      .color(color)
      .text(text);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {loc.x - box_size.x / 2, loc.y - box_size.y / 2};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::DrawBackground() const {
}

void MyApp::DrawMenu() {
  const cinder::vec2 center = getWindowCenter();
  const cinder::ivec2 size = {500, 50};
  const cinder::ColorA white = cinder::Color::white();
  const cinder::ColorA gray = cinder::Color::gray(0.75);

  // TODO: Refactor to decrease amount of repeated code
  if (level_ == 1) {
    PrintText("1: easy", gray, size,{center.x, center.y - 100});
  } else {
    PrintText("1: easy", white, size, {center.x, center.y - 100});
  }
  if (level_ == 2) {
    PrintText("2: medium", gray, size, center);
  } else {
    PrintText("2: medium", white, size, center);
  }

  if (level_ == 3) {
    PrintText("3: hard", gray, size,{center.x, center.y + 100});
  } else {
    PrintText("3: hard", white, size, {center.x, center.y + 100});
  }
}

void MyApp::keyDown(KeyEvent event) {
  if (state_ == GameState::kLevelSelect) {
    // TODO: Get rid of magic numbers? Declare as constants somewhere
    if (event.getChar() >= '1' && event.getChar() <= '3') {
      level_ = event.getChar() - '0';
    }
    if (event.getCode() == KeyEvent::KEY_s && level_ != 0) {
      state_ = GameState::kGameStart;
    }
  }
}

}  // namespace myapp
