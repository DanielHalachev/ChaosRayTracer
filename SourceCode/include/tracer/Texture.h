#pragma once

#include <string>
#include <variant>

#include "tracer/Color.h"
#include "tracer/Triangle.h"

class TextureBase {
 protected:
  std::string name;
  TextureBase(const std::string &name);

 public:
  const std::string &getName() const;
  TextureBase(const TextureBase &other) = default;
  TextureBase &operator=(const TextureBase &other) = default;
};

class AlbedoTexture : public TextureBase {
 private:
  Albedo albedo;

 public:
  AlbedoTexture(const std::string &name, const Albedo &albedo);
  const Color getColor(const Triangle & /*triangle*/, const Vector & /*barycentricCoordinates*/) const;
};

class EdgeTexture : public TextureBase {
 private:
  Color innerColor;
  Color edgeColor;
  float width;

 public:
  EdgeTexture(const std::string &name, const Color &innerColor, const Color &edgeColor, const float width);
  const Color getColor(const Triangle & /*triangle*/, const Vector &barycentricCoordinates) const;
};

class CheckerTexture : public TextureBase {
 private:
  Color colorA;
  Color colorB;
  float squareSize = 0;

 public:
  CheckerTexture(const std::string &name, const Color &colorA, const Color &colorB, const float squareSize);
  const Color getColor(const Triangle &triangle, const Vector &barycentricCoordinates) const;
};

class BitmapTexture : public TextureBase {
 private:
  int width;
  int height;
  int channels;
  std::vector<Color> buffer;

 public:
  BitmapTexture(const std::string &name, const std::string &filePath);
  const Color getColor(const Triangle &triangle, const Vector &barycentricCoordinates) const;
};

using Texture = std::variant<AlbedoTexture, EdgeTexture, CheckerTexture, BitmapTexture>;