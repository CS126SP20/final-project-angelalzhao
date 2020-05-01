//
// Created by angela on 4/28/2020.
//

#include "mylibrary/board.h"
#include "mylibrary/utils.h"

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
  // Set up gradient
  CreateGradient();
}

void Board::CreateGradient() {
  // Creating and placing tiles in the leftmost and rightmost columns
  for (int row = 1; row < size_ - 1; row ++) {
    // Generating gradient for left column
    cinder::Color tl_color = tiles_[0][0].GetColor();
    cinder::Color bl_color = tiles_[size_ - 1][0].GetColor();
    cinder::Color left_color = utils::GetGradientColor(tl_color, bl_color,
                                                       row, size_ - 1);
    // Generating gradient for right column
    cinder::Color tr_color = tiles_[0][size_ - 1].GetColor();
    cinder::Color br_color = tiles_[size_ - 1][size_ - 1].GetColor();
    cinder::Color right_color = utils::GetGradientColor(tr_color, br_color,
                                                        row, size_ - 1);
    // Creating tiles for the right and left side
    game::Tile left_tile(left_color, row, 0, true);
    game::Tile right_tile(right_color, row, size_ - 1, true);
    // Placing the tiles
    tiles_[row][0] = left_tile;
    tiles_[row][size_ - 1] = right_tile;
  }
  // Creating/placing the rest of the tiles
  for (int col = 1; col < size_ - 1; col++) {

    for (int row = 0; row < size_; row++) {
      cinder::Color left_color = tiles_[row][0].GetColor();
      cinder::Color right_color = tiles_[row][size_ - 1].GetColor();
      cinder::Color gradient_color = utils::GetGradientColor(left_color,
                                     right_color, col, size_ - 1);
      game::Tile tile(gradient_color, row, col, true);
      tiles_[row][col] = tile;
    }
  }
}

void Board::Select(int row, int col) {
  if (!CanSelect(row, col)) {
    return;
  }
  std::pair<int, int> tile_loc(row, col);
  selected_.push_back(tile_loc);
}

int Board::NumSelected() const { return selected_.size(); }

void Board::Swap() {
  // Swapping the positions of the two selected tiles in tiles_
  game::Tile temp = tiles_[selected_[0].first][selected_[0].second];
  tiles_[selected_[0].first][selected_[0].second] =
      tiles_[selected_[1].first][selected_[1].second];
  tiles_[selected_[1].first][selected_[1].second] = temp;
  // Clear selected
  selected_.clear();
}

bool Board::CanSelect(int row, int col) {
  if (row >= size_ || col >= size_ || selected_.size() == 2) {
    return false;
  }
  // Unmoveable tiles can't be selected
  if (!tiles_[row][col].CanTileMove()) {
    return false;
  }
  // We know the tile is moveable, so it is selectable if selected_ is empty
  if (selected_.empty()) {
    return true;
  }
  int selected_row = selected_[0].first;
  int selected_col = selected_[0].second;
  // Return true if the specified tile location is different than the already
  // selected tile location
  return selected_row != row || selected_col != col;
}

} // namespace game
