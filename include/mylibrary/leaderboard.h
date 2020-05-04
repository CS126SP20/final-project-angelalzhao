//
// Created by angela on 4/21/2020.
//

#ifndef FINALPROJECT_LEADERBOARD_H
#define FINALPROJECT_LEADERBOARD_H

#include "leaderboard.h"

#include <sqlite_modern_cpp.h>
#include <string>
#include <vector>

namespace game {

class Leaderboard {
 public:
  // Initializes the database
  explicit Leaderboard(const std::string& db_path);

  // Adds a score to the  leaderboard
  void AddScoreToLeaderBoard(int score, int level, const std::string & date);

  // Retrieves the top scores at the given level
  std::vector<std::string> RetrieveHighScores(const size_t limit, int level);

  // Returns the average score for the given level
  int GetAverageScore(int level);

 private:
  // Database containing scores/data from past games
  sqlite::database db_;
};

} // namespace game

#endif  // FINALPROJECT_LEADERBOARD_H
