//
// Created by angela on 4/30/2020.
//

#ifndef FINALPROJECT_UTILS_H
#define FINALPROJECT_UTILS_H

#include <cinder/Color.h>
#include <vector>

namespace utils {
// Generates a vector of the specified size of random colors
std::vector<cinder::Color> GetRandomColors(int num_colors);
// Returns a color in between the the two specified colors
// The index parameter is the position of the desired color. For example, if
// I wanted two colors in between first and second, the color closest to
// first would have index 1, the color closest to second would have index 2
// last_index is directly related to how many in between colors we want
cinder::Color GetGradientColor(const cinder::Color& first,
                               const cinder::Color& second, int index,
                               int last_index);

} // namespace utils

#endif  // FINALPROJECT_UTILS_H
