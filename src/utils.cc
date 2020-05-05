//
// Created by angela on 4/30/2020.
//

#include "mylibrary/utils.h"

#include <cstdlib>
#include <ctime>
#include <sstream>

namespace utils {

std::vector<cinder::Color> GetRandomColors(int num_colors) {
  std::vector<cinder::Color> colors;
  std::srand(std::time(nullptr));

  for (int i = 0; i < num_colors; i++) {
    // https://stackoverflow.com/questions/686353/random-float-number-generation
    float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    cinder::Color color(r, g, b);
    colors.push_back(color);
  }

  return colors;
}

cinder::Color GetGradientColor(const cinder::Color& first,
                               const cinder::Color& second, int index,
                               int last_index) {
  // Finding the difference in r, g, b values between the two colors
  float diff_r = second.r - first.r;
  float diff_g = second.g - first.g;
  float diff_b = second.b - first.b;
  // Calculating the "multiplier", or how much the new color differs from the
  // first color
  float multiplier = (float) index / last_index;
  // Calculating the r, g, b values of the new gradient color by linear map
  // from values in first to values in second
  float new_r = first.r + diff_r * multiplier;
  float new_g = first.g + diff_g * multiplier;
  float new_b = first.g + diff_b * multiplier;
  // Create/return the new color
  cinder::Color color(new_r, new_g, new_b);
  return color;
}

std::string GetDate() {
  // https://www.w3resource.com/cpp-exercises/basic/cpp-basic-exercise-34.php
  time_t t = std::time(nullptr);
  tm* t_ptr = localtime(&t);

  std::string date = std::to_string(t_ptr->tm_mon + 1) + "/";
  date.append(std::to_string(t_ptr->tm_mday));
  date.append("/");
  date.append(std::to_string(t_ptr->tm_year + 1900));

  return date;
}

} // namespace utils