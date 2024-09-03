#pragma once

#include "tracer/Vector.h"
class Vertex {
 private:
 public:
  Vector position;
  Vector normal;
  Vector UV;

 public:
  explicit Vertex(const Vector &position, const Vector &normal = Vector(), const Vector &UV = Vector());

  float &operator[](const unsigned short index);

  const float &operator[](const unsigned short index) const;
};