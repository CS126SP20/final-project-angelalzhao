// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <cinder/Color.h>
#include <mylibrary/board.h>
#include <mylibrary/tile.h>

#include <catch2/catch.hpp>
#include <vector>

TEST_CASE("Create default tile", "[tile]") {
  game::Tile tile;
  REQUIRE(tile.GetColor() == cinder::Color::black());
  REQUIRE(tile.GetCorrectRow() == 0);
  REQUIRE(tile.GetCorrectCol() == 0);
}

TEST_CASE("Create tile", "[tile]") {
  cinder::Color gray = cinder::Color::gray(0.5);
  game::Tile tile(gray, 1, 2, true);
  REQUIRE(tile.GetColor() == gray);
  REQUIRE(tile.GetCorrectRow() == 1);
  REQUIRE(tile.GetCorrectCol() == 2);
  REQUIRE(tile.CanTileMove());
}

TEST_CASE("Swap two tiles", "[tile]") {
  game::Tile first;
  game::Tile second(cinder::Color::gray(0.5), 1, 2, false);
  std::vector<game::Tile> tiles;
  tiles.push_back(first);
  tiles.push_back(second);
  // Swap first and second tiles
  game::Tile temp = tiles[0];
  tiles[0] = tiles[1];
  tiles[1] = temp;
  // Checking that the tiles were properly swapped
  REQUIRE(tiles[0].GetCorrectRow() == 1);
  REQUIRE(tiles[1].GetCorrectRow() == 0);
  REQUIRE(tiles[0].GetCorrectCol() == 2);
  REQUIRE(tiles[1].GetCorrectCol() == 0);
  REQUIRE(!tiles[0].CanTileMove());
  REQUIRE(tiles[1].CanTileMove());
}

// Test Board class logic
TEST_CASE("Set size", "[board]") {
  game::Board board;
  REQUIRE(board.GetSize() == 0);
  SECTION("SetSize() should change size") {
    board.SetSize(1);
    REQUIRE(board.GetSize() > 0);
  }
}

TEST_CASE("Set colors", "[board]") {
  const cinder::Color white = cinder::Color::white();
  game::Board board;
  board.SetSize(1);
  board.SetColors(white, white, white, white);
  REQUIRE(!board.GetTileAt(0, 0).CanTileMove());
  REQUIRE(board.GetTileAt(0, 0).GetColor() == white);
  REQUIRE(board.GetTileAt(0, 0).GetCorrectRow() == 0);
  REQUIRE(board.GetTileAt(0, 0).GetCorrectCol() == 0);
}

TEST_CASE("Select unmoveable tile", "[board]") {
  const cinder::Color white = cinder::Color::white();
  game::Board board;
  board.SetSize(2);
  board.SetColors(white, white, white, white);
  REQUIRE(board.NumSelected() == 0);
  SECTION("Try to select top left tile") {
    board.Select(0, 0);
    REQUIRE(board.NumSelected() == 0);
  }
  SECTION("Try to select bottom right tile") {
    board.Select(board.GetSize() - 1, board.GetSize() - 1);
  }
}

TEST_CASE("Select same tile twice", "[board]") {
  const cinder::Color black = cinder::Color::black();
  game::Board board;
  board.SetSize(3);
  board.SetColors(black, black, black, black);
  board.Select(1, 0);
  REQUIRE(board.NumSelected() == 1);
  SECTION("Try to select the same tile again") {
    board.Select(1, 0);
    REQUIRE(board.NumSelected() == 1);
  }
}

TEST_CASE("Try to select 3 tiles", "[board]") {
  const cinder::Color black = cinder::Color::black();
  game::Board board;
  board.SetSize(1);
  board.SetColors(black, black, black, black);
  board.Select(0, 1);
  board.Select(1, 0);
  board.Select(1, 1);
  REQUIRE(board.NumSelected() == 2);
}

TEST_CASE("Swapping two tiles", "[board]") {
  const cinder::Color black = cinder::Color::black();
  game::Board board;
  board.SetSize(2);
  board.SetColors(black, black, black, black);
  board.Select(1, 0);
  board.Select(0, 1);
  board.Swap();
  REQUIRE(board.NumSelected() == 0);
  REQUIRE(board.GetTileAt(1, 0).GetCorrectRow() == 0);
  REQUIRE(board.GetTileAt(1, 0).GetCorrectCol() == 1);
  REQUIRE(board.GetTileAt(0, 1).GetCorrectRow() == 1);
  REQUIRE(board.GetTileAt(0, 1).GetCorrectCol() == 0);
}

TEST_CASE("IsBoardSolved", "[board]") {
  cinder::Color white = cinder::Color::white();
  game::Board board;
  board.SetSize(2);
  board.SetColors(white, white, white, white);
  REQUIRE(board.IsBoardSolved());
  SECTION("Swapping two tiles") {
    board.Select(0, 1);
    board.Select(1, 1);
    board.Swap();
    REQUIRE_FALSE(board.IsBoardSolved());
  }
  SECTION("Swap tiles and swap back") {
    for (int i = 0; i < 2; i++) {
      board.Select(0, 1);
      board.Select(1, 1);
      board.Swap();
    }
    REQUIRE(board.IsBoardSolved());
  }
}

TEST_CASE("Shuffling", "[board]") {
  cinder::Color white = cinder::Color::white();
  game::Board board;
  board.SetSize(3);
  board.SetColors(white, white, white, white);
  board.Shuffle();
  REQUIRE_FALSE(board.IsBoardSolved());
}