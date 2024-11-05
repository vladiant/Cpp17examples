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

#include <execution>
#include <functional>
#include <iostream>
#include <numeric>  // for transform_reduce()
#include <vector>

void printSum(long num) {
  // create coll with num sequences of 1 2 3 4:
  std::vector<long> coll;
  coll.reserve(num * 4);
  for (long i = 0; i < num; ++i) {
    coll.insert(coll.end(), {1, 2, 3, 4});
  }

  auto sum =
      std::transform_reduce(std::execution::par, coll.begin(), coll.end(), 0L,
                            std::plus{}, [](auto val) { return val * val; });
  std::cout << "transform_reduce(): " << sum << '\n';
}

int main() {
  printSum(1);
  printSum(1000);
  printSum(1000000);
  printSum(10000000);

  return 0;
}
