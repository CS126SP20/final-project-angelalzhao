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

} // namespace utils