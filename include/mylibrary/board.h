//
// Created by angela on 4/28/2020.
//

#ifndef FINALPROJECT_BOARD_H
#define FINALPROJECT_BOARD_H

#include "tile.h"
#include <vector>
#include <cinder/Color.h>
#include <utility>

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
  // Selects the tile at the specified location (if possible) by adding its
  // current row/column to selected_
  void Select(int row, int col);
  // Returns the number of tiles selected (should be no more than 2)
  int NumSelected() const;
  // Swaps the two selected tiles (should only be called when two tiles are
  // selected)
  void Swap();
  // Checks if the board is solved (all tiles match with their correct location)
  bool IsBoardSolved();
  // Shuffles the tiles at the beginning of the game
  void Shuffle();

 private:
  // 2D vector of tiles representing the board's current state
  std::vector<std::vector<game::Tile>> tiles_;
  // The size of the board
  int size_;
  // Stores the location (row, column) of each selected tile
  // A maximum of two tiles will be selected, so the size should always be <= 2
  std::vector<std::pair<int, int>> selected_;
  // Creates and places non-corner tiles in gradient pattern
  // Called after corner tiles are placed
  void CreateGradient();
  // Returns true if the tile at the specified location can be selected
  // A tile can be selected only if it is moveable and not already selected
  bool CanSelect(int row, int col);
};

}

#endif  // FINALPROJECT_BOARD_H
