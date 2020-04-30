//
// Created by angela on 4/28/2020.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H

#include "tile.h"
#include <vector>
#include <cinder/Color.h>

namespace game {

class Board {
 public:
  // Default constructor
  Board();
  // Sets the size of the board based on difficulty (level must be positive)
  void SetSize(int level);
  // Sets the corner tiles based on the colors passed in
  // Creates new tiles arranged in the correct gradient pattern
  void SetColors(const cinder::Color& top_left, const cinder::Color& top_right,
                const cinder::Color& bottom_right,
                const cinder::Color& bottom_left);
  // Returns the size of the board
  int GetSize() const;
  // Returns the tile at the specified location (row, col must >= 0)
  game::Tile GetTileAt(int row, int col) const;

 private:
  // 2D vector of tiles representing the board's current state
  std::vector<std::vector<game::Tile>> tiles_;
  // The size of the board
  int size_;
  // Creates and places non-corner tiles in gradient pattern
  // Called after corner tiles are placed
  void CreateGradient();
};

}

#endif  // FINALPROJECT_BOARD_H
