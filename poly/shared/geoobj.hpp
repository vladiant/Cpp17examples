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

#include <memory>
#include <string>

#include "coord.hpp"

// abstract base class
class GeoObj {
 protected:
  std::string name;                 // name of the geometric object
  GeoObj(const GeoObj&) = default;  // disable slicing
  GeoObj(GeoObj&&) = default;       // disable slicing
 public:
  GeoObj(std::string n = {}) : name{n} {}

  virtual std::string getName() && final { return std::move(name); }
  virtual const std::string& getName() const& final { return name; }

  virtual void move(Coord) = 0;
  virtual void draw() const = 0;

  virtual ~GeoObj() = default;
  GeoObj& operator=(const GeoObj&) = delete;  // disable slicing
  GeoObj& operator=(GeoObj&&) = delete;       // disable slicing

  [[nodiscard]] virtual std::shared_ptr<GeoObj> clone() const = 0;
};
