//
// Created by angela on 4/25/2020.
//

#ifndef FINALPROJECT_TILE_H
#define FINALPROJECT_TILE_H

#include <cinder/Color.h>

namespace game {

class Tile {
 public:
  // Default constructor
  Tile();

  // Constructor that sets the color, row, column
  Tile(const cinder::Color& color, int correct_row, int correct_col,
      bool can_move);

  // Returns the color of the tile
  cinder::Color GetColor() const;

  // Returns the correct row (the row in which the tile is located in the
  // solved puzzle)
  int GetCorrectRow() const;

  // Returns the correct column
  int GetCorrectCol() const;

  // Returns whether or not the tile is moveable
  bool CanTileMove() const;

 private:
  // The color of the tile
  cinder::Color color_;
  // The row the tile belongs to in the solved board
  int correct_row_;
  // The column the tile belongs to in the solved board
  int correct_col_;
  // Whether or not the tile can move (corner tiles are fixed)
  bool can_tile_move_;
};

} // namespace game

#endif  // FINALPROJECT_TILE_H
