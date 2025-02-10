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

#pragma once

#include <iostream>

#include "geoobj.hpp"

class Line : public GeoObj {
 private:
  Coord from;
  Coord to;

 public:
  Line(std::string n, Coord f, Coord t)
      : GeoObj{std::move(n)}, from{f}, to{t} {}

  virtual void move(Coord c) override {
    from += c;
    to += c;
  }
  virtual void draw() const override {
    std::cout << "line '" << name << "' from " << from << " to " << to << '\n';
  }

  [[nodiscard]] virtual std::shared_ptr<GeoObj> clone() const override {
    return std::make_shared<Line>(*this);
  }
};
