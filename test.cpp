#include "shapefinder.hpp"

using namespace cv;
using namespace std;

void cosineTest(Point p1, Point p2, Point c, double expResult) {
  assert(cosine(p1, p2, c) - expResult < 1e-5);
}

int main() {
  Point p1(0, 1);
  Point p2(1, 0);
  Point center(0, 0);
  cosineTest(p1, p1, center, 1);
  cosineTest(p1, p2, center, 0.0);
  return 0;
}
