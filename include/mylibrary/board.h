//
// Created by angela on 4/28/2020.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H

#include "tile.h"
#include <vector>

namespace game {

class Board {
 public:
  // Default constructor
  Board();
  // Sets the size of the board based on difficulty level
  void SetSize(int level);
  // Returns the size of the board
  int GetSize() const;

 private:
  // 2D vector of tiles representing the board's current state
  std::vector<std::vector<game::Tile>> tiles_;
  // The size of the board
  int size_;
};

}

#endif  // FINALPROJECT_BOARD_H
