//
// Created by angela on 4/30/2020.
//

#include "mylibrary/utils.h"

#include <cstdlib>
#include <ctime>

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

} // namespace utils