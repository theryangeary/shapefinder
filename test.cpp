#include "./shapefinder.hpp"

using namespace cv;
using namespace std;

void cosineTest(Point p1, Point p2, Point c, double expResult) {
  assert(cosine(p1, p2, c) - expResult < 1e-5);
}

void colorTest(string color, cv::Scalar result) {
  Scalar colorResult = *getColorFromColorMap(color);
  assert((colorResult)[0] == result[0] &&
         (colorResult)[1] == result[1] &&
         (colorResult)[2] == result[2]);
}

int main() {
  Point p1(0, 1);
  Point p2(1, 0);
  Point center(0, 0);
  cosineTest(p1, p1, center, 1);
  cosineTest(p1, p2, center, 0.0);
  colorTest("blue", Scalar(255, 0, 0));
  colorTest("green", Scalar(0, 255, 0));
  colorTest("red", Scalar(0, 0, 255));
  return 0;
}
