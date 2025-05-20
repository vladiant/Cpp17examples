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
#include <cstdlib>  // for std::byte
#include <iostream>
#include <memory_resource>
#include <string>
#include <vector>

#include "tracknew.hpp"

int main() {
  {
    std::cout << "non-SSO string\n";
    TrackNew::reset();

    std::vector<std::string> coll;
    for (int i = 0; i < 1000; ++i) {
      coll.emplace_back("just a non-SSO string");
    }

    TrackNew::status();
  }

  {
    std::cout << "pmr vector\n";
    TrackNew::reset();

    // allocate some memory on the stack:
    std::array<std::byte, 200000> buf;

    // and use it as initial memory pool for a vector:
    std::pmr::monotonic_buffer_resource pool{buf.data(), buf.size()};
    std::pmr::vector<std::string> coll{&pool};

    for (int i = 0; i < 1000; ++i) {
      coll.emplace_back("just a non-SSO string");
    }

    TrackNew::status();
  }

  {
    std::cout << "pmr vector of strings\n";
    TrackNew::reset();

    // allocate some memory on the stack:
    std::array<std::byte, 200000> buf;

    // and use it as initial memory pool for a vector and its strings:
    std::pmr::monotonic_buffer_resource pool{buf.data(), buf.size()};
    std::pmr::vector<std::pmr::string> coll{&pool};

    for (int i = 0; i < 1000; ++i) {
      coll.emplace_back("just a non-SSO string");
    }

    TrackNew::status();
  }

  {
    std::cout << "pmr vector of strings different sizes\n";
    // allocate some memory on the stack:
    std::array<std::byte, 200000> buf;

    for (int num : {1000, 2000, 500, 2000, 3000, 50000, 1000}) {
      std::cout << "-- check with " << num << " elements:\n";
      TrackNew::reset();

      std::pmr::monotonic_buffer_resource pool{buf.data(), buf.size()};
      std::pmr::vector<std::pmr::string> coll{&pool};
      for (int i = 0; i < num; ++i) {
        coll.emplace_back("just a non-SSO string");
      }

      TrackNew::status();
    }
  }

  return 0;
}
