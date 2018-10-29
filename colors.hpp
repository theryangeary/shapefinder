#include "opencv2/core/types.hpp"
#include "opencv2/core/core.hpp"
#include <map>

#define BLUE   Scalar(255,0,0)
#define GREEN Scalar(0,255,0)
#define RED  Scalar(0,0,255)
#define WHITE Scalar(255,255,255)

std::map<std::string, cv::Scalar> colorMap = {
  {"red", cv::RED},
  {"green", cv::GREEN},
  {"blue", cv::BLUE},
  {"white", cv::WHITE}
};

