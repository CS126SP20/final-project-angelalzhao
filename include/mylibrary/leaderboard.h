//
// Created by angela on 4/21/2020.
//

#ifndef FINALPROJECT_LEADERBOARD_H
#define FINALPROJECT_LEADERBOARD_H

#include "leaderboard.h"

#include <sqlite_modern_cpp.h>

namespace game {

class Leaderboard {
 public:
  explicit Leaderboard(const std::string& db_path);

 private:
  sqlite::database db_;
};

} // namespace game

#endif  // FINALPROJECT_LEADERBOARD_H
