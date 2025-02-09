#include <iostream>
#include <ostream>
#include <string>

#include "tracer/RayTracer.h"
#include "tracer/SceneParser.h"

int main() {
  SceneParser parser;
  for (short i = 0; i < 4; i++) {
    std::cout << i << '\n';
    Scene scene = parser.parseScene("scene" + std::to_string(i) + ".crtscene", "/home/daniel");
    RayTracer tracer(scene);
    // RenderOptions options{BVHBucketsQueue, 5, true, 1, 128};
    RenderOptions options{BVHBucketsThreadPool, 5, false};
    tracer.render("/home/daniel/result" + std::to_string(i) + ".ppm", options);
    std::cout << '\n';
  }
  return 0;
}