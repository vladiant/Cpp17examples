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
#include <iostream>
#include <numeric>  // for reduce()
#include <vector>

void printSum(long num) {
  // create coll with num sequences of 1 2 3 4:
  std::vector<long> coll;
  coll.reserve(num * 4);
  for (long i = 0; i < num; ++i) {
    coll.insert(coll.end(), {1, 2, 3, 4});
  }

  auto squaredSum = [](auto sum, auto val) { return sum + val * val; };

  auto sum = std::reduce(std::execution::par, coll.begin(), coll.end(), 0L,
                         squaredSum);
  std::cout << "reduce():     " << sum << '\n';
}

int main() {
  printSum(1);
  printSum(1000);
  printSum(1000000);
  printSum(10000000);

  return 0;
}
