#include "opencv2/core.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;

#include <iostream>
using namespace std;

double cosine(cv::Point p1, cv::Point center, cv::Point p2);
void findPolygon(const UMat& image, vector<vector<Point>>& squares, int shape);
UMat drawPolygonSquaresBoth(const UMat& image, const vector<vector<Point>>& sqs, Scalar color);
void drawPolygons(UMat& _image, const vector<vector<Point>>& squares, Scalar color);
Scalar* getColorFromColorMap(string color);

int entry(string inputName, string outfile, string color, string shape);
