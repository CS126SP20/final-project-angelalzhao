// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"


#include <cinder/app/App.h>
#include <cinder/gl/gl.h>
#include <cinder/Color.h>
#include <sqlite_modern_cpp.h>


namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp()
  : leaderboard_{"gay.db"} {}

void MyApp::setup() {

}

void MyApp::update() { }

void MyApp::draw() {
  DrawBackground();
}

void MyApp::DrawBackground() const {
  cinder::gl::clear(cinder::Color(0.75, 1, 0.75));
}

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
