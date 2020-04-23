// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"


#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/Color.h>


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
  DrawBackground();
}

void MyApp::DrawBackground() const {
  cinder::gl::clear(cinder::Color(0.75, 1, 0.75));
}

void MyApp::keyDown(KeyEvent event) {
  if (state_ == GameState::kLevelSelect) {
    // TODO: Get rid of magic numbers? Declare as constants somewhere
    if (event.getChar() >= '1' && event.getChar() <= '3') {
      level_ = event.getChar() - '0';
    }
  }
}

}  // namespace myapp
