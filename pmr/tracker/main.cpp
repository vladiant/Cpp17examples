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

#include <iostream>
#include <memory_resource>
#include <string>
#include <vector>

#include "tracker.hpp"

int main() {
  {
    // track allocating chunks of memory (starting with 10k) without
    // deallocating:
    Tracker track1{"keeppool:"};
    std::pmr::monotonic_buffer_resource keeppool{10000, &track1};
    {
      Tracker track2{"  syncpool:", &keeppool};
      std::pmr::synchronized_pool_resource pool{&track2};

      for (int j = 0; j < 100; ++j) {
        std::pmr::vector<std::pmr::string> coll{&pool};
        coll.reserve(100);
        for (int i = 0; i < 100; ++i) {
          coll.emplace_back("just a non-SSO string");
        }
        if (j == 2) std::cout << "--- third iteration done\n";
      }  // deallocations are given back to pool, but not deallocated
      // so far nothing was allocated
      std::cout << "--- leave scope of pool\n";
    }
    std::cout << "--- leave scope of keeppool\n";
  }  // deallocates all allocated memory

  return 0;
}
