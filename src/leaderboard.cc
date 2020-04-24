//
// Created by angela on 4/21/2020.
//

#include "mylibrary/leaderboard.h"

namespace game {

Leaderboard::Leaderboard(const std::string& db_path) : db_{db_path} {
  db_ << "CREATE TABLE if not exists leaderboard (\n"
         "  date  TEXT NOT NULL,\n"
         "  score INTEGER NOT NULL,\n"
         "  level INTEGER NOT NULL\n"
         ");";
}

} // namespace game