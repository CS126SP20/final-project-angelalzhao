// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <mylibrary/leaderboard.h>
#include <cinder/app/App.h>


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

 private:
  game::Leaderboard leaderboard_;
  int level_;
  GameState state_;

 private:
  void DrawBackground() const;
  void DrawMenu();
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
