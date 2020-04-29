//
// Created by angela on 4/28/2020.
//

#include "mylibrary/board.h"

namespace game {

Board::Board() {
  size_ = 0;
}

void Board::SetSize(int level) {
  // Level 1 would be 3x3, and the size increases by 2 every level
  size_ = 2 * level + 1;
  // Setting up the tiles vector
  // Insert the correct amount of default tiles so we can modify the tiles
  // vector in the same way as a 2D array
  game::Tile temp;
  for (int row = 0; row < size_; row++) {
    std::vector<game::Tile> row_vec;
    for (int col = 0; col < size_; col++) {
      row_vec.push_back(temp);
    }
    tiles_.push_back(row_vec);
  }
}

int Board::GetSize() const {
  return size_;
}

}
