#include "parser/input_parser.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  // ./unittest_input_parser -p /home/rx/Documents/3DGenerator/data -n
  // zhongli.jpeg -t pic -o result -s zhongli.mesh -e mesh
  InputParser parser(argc, argv);

  std::cout << "Input Data:" << std::endl;
  std::cout << "  File Path: " << parser.getInputData().filePath << std::endl;
  std::cout << "  File Name: " << parser.getInputData().fileName << std::endl;
  std::cout << "  File Type: " << parser.getInputData().fileType << std::endl;

  std::cout << "Output Data:" << std::endl;
  std::cout << "  Output File Path: " << parser.getOutputData().outputFilePath
            << std::endl;
  std::cout << "  Output File Name: " << parser.getOutputData().outputFileName
            << std::endl;
  std::cout << "  Output File Type: " << parser.getOutputData().outputFileType
            << std::endl;

  return 0;
}
