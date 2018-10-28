#include "shapefinder.hpp"

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
  cout << inputFile << endl << outfile << endl << shape << endl << color << endl;
  entry(inputFile, outfile, color, shape);
  return 0;
}
