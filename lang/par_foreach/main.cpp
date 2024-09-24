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

#include <algorithm>
#include <chrono>
#include <cmath>      // for sqrt()
#include <execution>  // for the execution policy
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

/********************************************
 * timer to print elapsed time
 ********************************************/

class Timer {
 private:
  std::chrono::steady_clock::time_point last;

 public:
  Timer() : last{std::chrono::steady_clock::now()} {}
  void printDiff(const std::string& msg = "Timer diff: ") {
    auto now{std::chrono::steady_clock::now()};
    std::chrono::duration<double, std::milli> diff{now - last};
    std::cout << msg << diff.count() << "ms\n";
    last = std::chrono::steady_clock::now();
  }
};

int main() {
  int numElems = 1000;

  struct Data {
    double value;  // initial value
    double sqrt;   // parallel computed square root
  };

  // initialize numElems values without square root:
  std::vector<Data> coll;
  coll.reserve(numElems);
  for (int i = 0; i < numElems; ++i) {
    coll.push_back(Data{i * 4.37, 0});
  }

  // parallel computation of square roots:
  Timer t;
  for_each(std::execution::par, coll.begin(), coll.end(),
           [](auto& val) { val.sqrt = std::sqrt(val.value); });
  t.printDiff("parallel:   ");
  std::cout << '\n';

  return 0;
}
