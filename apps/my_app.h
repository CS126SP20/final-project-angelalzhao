// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <mylibrary/leaderboard.h>
#include <mylibrary/board.h>
#include <cinder/app/App.h>
#include <cinder/audio/audio.h>
#include <vector>
#include <string>


namespace myapp {

enum class GameState {
  kLevelSelect,
  kGameStart,
  kPlaying,
  kGameEnded,
  kLeaderboard,
};

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;
  void mouseDown(cinder::app::MouseEvent) override;

 private:
  // Leaderboard object that adds scores, retrieves scores, gets average score
  game::Leaderboard leaderboard_;
  // Difficulty level chosen at the start of the game (1 is easy, 3 is hard)
  int level_;
  // The current state/phase of the game
  GameState state_;
  // Represents the game board
  game::Board board_;
  // The number of moves the player made in the game
  int score_;
  // Stores the top scores at the current level in the form "[score] - [date]"
  std::vector<std::string> top_scores_;
  // The time that the player won the game
  time_t time_ended_;
  // Sound effect to be played when the player wins
  cinder::audio::VoiceRef win_sound_;

 private:
  void DrawMenu();
  void DrawBoard();
  void DrawTopScores();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
