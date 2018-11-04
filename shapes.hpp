#include <iostream>

#define TRIANGLE  0
#define RECTANGLE 1
#define SQUARE    2
#define NUMSHAPES 3

int getShape(std::string name) {
  if (name == "triangle") {
    return TRIANGLE;
  }
  else if (name == "rectangle") {
    return RECTANGLE;
  }
  else if (name == "square") {
    return SQUARE;
  }
  else {
    return -1;
  }
}
