#include "tracer/Material.h"

#include <variant>

Material::Material(const Texture &texture, const Albedo &albedo, const MaterialType &type, const bool smoothShading,
                   const float ior)
    : texture{&texture}, albedo{albedo}, type{type}, smoothShading{smoothShading}, ior{ior} {};

Material::Material(const Albedo &albedo, const MaterialType &type, const bool smoothShading, const float ior)
    : texture{nullptr}, albedo{albedo}, type{type}, smoothShading{smoothShading}, ior{ior} {};

Material::Material(const Material &other)
    : texture{other.texture},
      albedo{other.albedo},
      type{other.type},
      smoothShading{other.smoothShading},
      ior{other.ior} {}

Material::Material(Material &&other) noexcept
    : texture{other.texture},
      albedo{other.albedo},
      type{other.type},
      smoothShading{other.smoothShading},
      ior{other.ior} {}

bool Material::hasTexture() const {
  return this->texture != nullptr;
}

Color Material::getColor(const Triangle &triangle, const Vector &barycentricCoordinates) const {
  if (this->hasTexture()) {
    return std::visit([&](const auto &texture) { return texture.getColor(triangle, barycentricCoordinates); },
                      *texture);
  } else {
    return this->albedo;
  }
}