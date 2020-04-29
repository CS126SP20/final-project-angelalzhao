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

game::Tile Board::GetTileAt(int row, int col) const {
  return tiles_[row][col];
}

void Board::SetColors(const cinder::Color& top_left,
                      const cinder::Color& top_right,
                      const cinder::Color& bottom_right,
                      const cinder::Color& bottom_left) {
  // Create tiles representing the corner tiles that are fixed (unmovable)
  game::Tile tl(top_left, 0, 0, false);
  game::Tile tr(top_right, 0, size_ - 1, false);
  game::Tile br(bottom_right, size_ - 1, size_ - 1, false);
  game::Tile bl(bottom_left, size_ - 1, 0, false);
  // Add them to the tiles vector at the correct positions
  tiles_[0][0] = tl;
  tiles_[0][size_ - 1] = tr;
  tiles_[size_ - 1][size_ - 1] = br;
  tiles_[size_ - 1][0] = bl;
}

} // namespace game
