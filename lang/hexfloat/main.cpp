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

#include <iomanip>
#include <iostream>

int main() {
  // init list of floating-point values:
  std::initializer_list<double> values{
      0x1p4,        // 16
      0xA,          // 10
      0xAp2,        // 40
      5e0,          // 5
      0x1.4p+2,     // 5
      1e5,          // 100000
      0x1.86Ap+16,  // 100000
      0xC.68p+2,    // 49.625
  };

  // print all values both as decimal and hexadecimal value:
  for (double d : values) {
    std::cout << "dec: " << std::setw(6) << std::defaultfloat << d
              << "  hex: " << std::hexfloat << d << '\n';
  }
  return 0;
}
