//
// Created by angela on 4/25/2020.
//

#include "mylibrary/tile.h"

namespace game {

Tile::Tile() {
  color_ = cinder::Color::black();
  correct_row_ = 0;
  correct_col_ = 0;
  can_tile_move_ = true;
}

Tile::Tile(const cinder::Color& color, int correct_row, int correct_col,
            bool can_move) {
  color_ = color;
  correct_row_ = correct_row;
  correct_col_ = correct_col;
  can_tile_move_ = can_move;
}

cinder::Color Tile::GetColor() const {
  return color_;
}

int Tile::GetCorrectRow() const {
  return correct_row_;
}

int Tile::GetCorrectCol() const {
  return correct_col_;
}

bool Tile::CanTileMove() const {
  return can_tile_move_;
}

}
