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

#include "tracknew.hpp"

#include <iostream>
#include <string>

int main() {
  TrackNew::reset();
  TrackNew::trace(true);
  std::string s = "string value with 26 chars";
  auto p1 = new std::string{"an initial value with even 35 chars"};
  auto p2 = new (std::align_val_t{64}) std::string[4];
  auto p3 = new std::string[4]{"7 chars", "x", "or 11 chars",
                               "a string value with 28 chars"};
  TrackNew::status();
  //...
  delete p1;
  delete[] p2;
  delete[] p3;
}
