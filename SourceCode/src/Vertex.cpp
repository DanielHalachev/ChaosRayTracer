#include "tracer/Vertex.h"

Vertex::Vertex(const Vector &position, const Vector &normal, const Vector &UV)
    : position{position}, normal{normal}, UV{UV} {};

float &Vertex::operator[](const unsigned short index) {
  return this->position[index];
}

const float &Vertex::operator[](const unsigned short index) const {
  return this->position[index];
}