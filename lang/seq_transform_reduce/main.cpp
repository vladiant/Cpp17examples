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
#include <numeric>

int main() {
  std::array coll{3, 1, 7, 5, 4, 1, 6, 3};

  auto twice = [](int v) { return v * 2; };

  // process sum of doubled values of elements:
  std::cout << "sum of doubles: "
            << std::transform_reduce(coll.cbegin(), coll.cend(),  // range
                                     0, std::plus{}, twice)
            << '\n';

  // process sum of squared values:
  std::cout << "sum of squared: "
            << std::transform_reduce(coll.cbegin(), coll.cend(),  // range
                                     0L, std::plus{},
                                     [](auto v) { return v * v; })
            << '\n';
  return 0;
}
