#pragma once
#include "tracer/Color.h"
#include "tracer/Texture.h"

enum MaterialType { Diffuse, Reflective, Constant, Refractive };

class Material {
 public:
  explicit Material(const Texture &texture, const Albedo &albedo, const MaterialType &type = Diffuse,
                    const bool smoothShading = false, const float ior = 1.0f);
  explicit Material(const Albedo &albedo, const MaterialType &type = Diffuse, const bool smoothShading = false,
                    const float ior = 1.0f);
  Material(const Material &other);
  Material(Material &&other) noexcept;
  Material &operator=(const Material &other) = delete;
  Material &operator=(Material &&other) noexcept = delete;

  bool hasTexture() const;
  Color getColor(const Triangle &triangle, const Vector &barycentricCoordinates) const;

 public:
  const Texture *const texture = nullptr;
  Albedo albedo;
  MaterialType type;
  bool smoothShading;
  float ior;
};