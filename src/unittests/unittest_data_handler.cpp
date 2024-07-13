#include "parser/data_handler.hpp"
#include "parser/input_parser.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  // ./unittest_input_parser -p /home/rx/Documents/3DGenerator/data -n
  // zhongli.jpeg -t pic -o result -s zhongli.mesh -e mesh
  InputParser parser(argc, argv);

  DataHandler data_handler();

  return 0;
}
