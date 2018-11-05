#include "shapefinder.hpp"

void usage() {
  cout << "Usage: ";
  cout << "./main <image>" << endl;
  cout << "\tOptions:" << endl;
  cout << "\t-c, --color\tColor to outline found shapes with. One of red, blue, green, or a hex color such as \"#74fed9\". If no color is specified, red will be used." << endl;
  cout << "\t-o, --output\tPath to save output to. If no extension is specified then .png will be used." << endl;
  cout << "\t-s, --shape\tShape to find. One of rectangle or triangle. If not shape is specified, rectangle will be used." << endl;
}

int main(int argc, char** argv) {
  string inputFile = "";
  string outfile = "./images/output.png";
  string color = "#ff0000";
  string shape = "rectangle";
  int i;
  for(i = 1; i < argc; i++) {
    if (0 == strcmp(argv[i], "-o") || 0 == strcmp(argv[i], "--output")) {
      outfile = argv[i+1];
      i++;
    }
    else if (0 == strcmp(argv[i], "-c") || 0 == strcmp(argv[i], "--color")) {
      color = argv[i+1];
      i++;
    }
    else if (0 == strcmp(argv[i], "-s") || 0 == strcmp(argv[i], "--shape")) {
      shape = argv[i+1];
      i++;
    }
    else {
      inputFile = argv[i];
    }
  }
  cout << "Input: " << inputFile << endl;
  cout << "Output: " << outfile << endl;
  cout << "Shape: " << shape << endl;
  cout << "Color: " << color << endl;
  try {
    if (entry(inputFile, outfile, color, shape) == EXIT_FAILURE) {
      usage();
    }
  }
  catch (Exception e) {
    usage();
  }
  return 0;
}
