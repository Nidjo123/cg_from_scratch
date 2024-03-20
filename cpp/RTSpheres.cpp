#include "App.h"
#include <cmath>
#include <cstdlib>

#include <math/Vector.h>

class RTSpheres : public App {
public:
  using App::App;

private:
  void Render() override;
};

void RTSpheres::Render() {
  for (auto x = -100; x < 100; x++)
    canvas_.PutPixel(x, 0, Color{255, 255, 255});
}

int main() {
  Vector3f v{1, 2, 3};
  std::cout << v << std::endl;

  RTSpheres app{"Raytracing Spheres", 512, 512};
  app.Run();
  return EXIT_SUCCESS;
}
