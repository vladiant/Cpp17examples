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

#include <array>
#include <cassert>
#include <iostream>

#include "geoobj.hpp"

class Polygon : public GeoObj {
 private:
  std::array<Coord, 100> points;
  int size;

 public:
  // constructor for list of Coord's
  Polygon(std::string n, std::initializer_list<Coord> pl)
      : GeoObj{std::move(n)}, size{static_cast<int>(pl.size())} {
    assert(pl.size() <= points.size());
    int idx{0};
    for (const auto& p : pl) {
      points[idx++] = p;
    }
  }

  virtual void move(Coord c) override {
    for (int i = 0; i < size; ++i) {
      points[i] += c;
    }
  }
  virtual void draw() const override {
    std::cout << "polygon '" << name << "' over";
    for (int i = 0; i < size; ++i) {
      std::cout << " " << points[i];
    }
    std::cout << "\n";
  }

  virtual int numPoints() const final { return size; }

  [[nodiscard]] virtual std::unique_ptr<GeoObj> clone() const override {
    return std::make_unique<Polygon>(*this);
  }
};
