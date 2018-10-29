#include "opencv2/core/types.hpp"
#include "opencv2/core/core.hpp"
#include <map>

#define RED   Scalar(255,0,0)
#define GREEN Scalar(0,255,0)
#define BLUE  Scalar(0,0,255)


std::map<std::string, cv::Scalar> colorMap = {
  {"red", cv::RED},
  {"green", cv::GREEN},
  {"blue", cv::BLUE}
};

