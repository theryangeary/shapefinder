#include "opencv2/core.hpp"
#include "opencv2/core/ocl.hpp"
#include "opencv2/core/utility.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
using namespace cv;
#include "shapefinder.hpp"
#include "colors.hpp"

int thresh = 50;
int N = 11;

/**
   Find the cosine between three Points.
*/
double cosine(Point pt1, Point pt2, Point pt0) {
  double dx1 = pt1.x - pt0.x;
  double dy1 = pt1.y - pt0.y;
  double dx2 = pt2.x - pt0.x;
  double dy2 = pt2.y - pt0.y;
  return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}

/**
   Find squares in image
*/
void findSquares(const UMat& image, vector<vector<Point>>& squares) {
  squares.clear();
  UMat pyr, time, gray0(image.size(), CV_8U), gray;

  pyrDown(image, pyr, Size(image.cols/2, image.rows/2));
  pyrUp(pyr, time, image.size());
  vector<vector<Point>> contours;

  // loop through R,G,B
  for(int c = 0; c < 3; c++) {
    int ch[] = {c, 0};
    mixChannels(time, gray0, ch, 1);

    for(int l = 0; l < N; l++) {
      if(l == 0) {
        Canny(gray0, gray, 0, thresh, 5);
        dilate(gray, gray, UMat(), Point(-1, -1));
      }
      else {
        threshold(gray0, gray, (l+1)*255/N, 255, THRESH_BINARY);
      }

      findContours(gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

      vector<Point> approx;

      for(size_t i = 0; i < contours.size(); i++) {
        approxPolyDP(contours[i], approx, arcLength(contours[i], true)*0.02, true);

        if(approx.size() == 4 && fabs(contourArea(approx)) > 1000 && isContourConvex(approx)) {
            double maxCosine = 0;
            for(int j = 2; j < 5; j++) {
              double cosineResult = fabs(cosine(approx[j%4], approx[j-2], approx[j-1]));
              maxCosine = MAX(maxCosine, cosineResult);
            }
            if(maxCosine < 0.3) {
              squares.push_back(approx);
            }
          }
      }
    }
  }
}

/**
   Draw outlines on squares in image
*/
void drawSquares(UMat& _image, const vector<vector<Point>>& squares, Scalar color) {
  Mat image = _image.getMat(ACCESS_WRITE);
  for(size_t i = 0; i < squares.size(); i++)
    {
      const Point* p = &squares[i][0];
      int n = (int) squares[i].size();
      polylines(image, &p, &n, 1, true, color, 3, LINE_AA);
    }
}

/**
   Draw squares on a single image
*/
UMat drawSquaresBoth(const UMat& image, const vector<vector<Point>>& sqs, Scalar color) {
  UMat imgToShow(Size(image.cols, image.rows), image.type());
  image.copyTo(imgToShow);
  drawSquares(imgToShow, sqs, color);
  return imgToShow;
}

/**
   Getter for colorMap
*/
Scalar* getColorFromColorMap(string color) {
  return &colorMap[color];
}

int entry(string inputName, string outfile, string color, string shape) {
    int iterations = 10;
    vector<vector<Point> > squares;
    UMat image;
    imread(inputName, 1).copyTo(image);
    if(image.empty()) {
        cout << "Couldn't load " << inputName << endl;
        return EXIT_FAILURE;
    }
    int j = iterations;
    int64 t_cpp = 0;
    findSquares(image, squares);
    do {
        int64 t_start = getTickCount();
        findSquares(image, squares);
        t_cpp += cv::getTickCount() - t_start;
        t_start  = getTickCount();
    }
    while(--j);
    Scalar* drawColor = getColorFromColorMap(color);
    UMat result = drawSquaresBoth(image, squares, *drawColor);
    try {
      imwrite(outfile, result);
    }
    catch (cv::Exception e) {
      string outfileWithExtension = outfile + ".png";
      imwrite(outfileWithExtension, result);
    }
    return EXIT_SUCCESS;
}
