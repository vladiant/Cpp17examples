//********************************************************
// The following code example is taken from the book
//  C++17 - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppstd17.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************

#include <array>
#include <iostream>
#include <iterator>
#include <vector>

template <typename T>
void printData(const T& coll) {
  // print every second element:
  for (std::size_t idx{0}; idx < std::size(coll); ++idx) {
    if (idx % 2 == 0) {
      std::cout << std::data(coll)[idx] << ' ';
    }
  }
  std::cout << '\n';
}

int main() {
  auto container_a = {1, 2, 3, 4, 5, 6};
  printData(container_a);

  int container_b[]{7, 8, 9, 10, 11, 12};
  printData(container_b);

  std::array<int, 6> container_c{13, 14, 15, 16, 17, 18};
  printData(container_c);

  std::vector<int> container_d{19, 20, 21, 22, 23, 24};
  printData(container_d);

  return 0;
}
