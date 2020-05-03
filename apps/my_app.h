// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <mylibrary/leaderboard.h>
#include <mylibrary/board.h>
#include <cinder/app/App.h>
#include <vector>
#include <string>


namespace myapp {

enum class GameState {
  kLevelSelect,
  kGameStart,
  kPlaying,
  kGameEnded,
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
  game::Leaderboard leaderboard_;
  int level_;
  GameState state_;
  game::Board board_;
  int score_;
  std::vector<std::string> top_scores_;

 private:
  void DrawBackground() const;
  void DrawMenu();
  void DrawBoard();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
