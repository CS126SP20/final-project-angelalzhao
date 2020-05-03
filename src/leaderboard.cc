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

void Leaderboard::AddScoreToLeaderBoard(int score, int level,
                                        const std::string& date) {
  db_ << "insert into leaderboard (level,score,date) values (?,?,?);"
      << level
      << score
      << date;
}
std::vector<std::string> GetScores(sqlite::database_binder* rows) {
  std::vector<std::string> scores;

  for (auto&& row : *rows) {
    int score;
    std::string date;
    row >> score >> date;
    std::string formatted_score = std::to_string(score) + " - " + date;
    scores.push_back(formatted_score);
  }

  return scores;
}
std::vector<std::string> Leaderboard::RetrieveHighScores(const size_t limit,
                                                         int level) {
  auto rows = db_ << "SELECT score,date FROM leaderboard WHERE level = ? "
                     "ORDER BY score ASC LIMIT ?;"
                  << level
                  << limit;
  return GetScores(&rows);
}

} // namespace game