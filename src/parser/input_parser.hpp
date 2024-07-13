// #include <iostream>
// #include <string>
// #include <map>

// #include <boost/program_options.hpp>

// namespace po = boost::program_options;

// class InputParser {
// public:
//     struct InputData {
//         std::string filePath;
//         std::string fileName;
//         std::string fileType; // video, image, pointcloud
//     };

//     struct OutputData {
//         std::string outputFilePath;
//         std::string outputFileName;
//         std::string outputFileType; // video, image, pointcloud
//     };

//     InputParser(int argc, char* argv[]) {
//         parseOptions(argc, argv);
//     }

//     InputData getInputData() const {
//         return inputData_;
//     }

//     OutputData getOutputData() const {
//         return outputData_;
//     }

// private:
//     void parseOptions(int argc, char* argv[]) {
//         po::options_description desc("Allowed options");
//         desc.add_options()
//             ("help", "produce help message")
//             ("input-path,p", po::value<std::string>(&inputData_.filePath), "input file path")
//             ("input-name,n", po::value<std::string>(&inputData_.fileName), "input file name")
//             ("input-type,t", po::value<std::string>(&inputData_.fileType), "input file type (video, image, pointcloud)")
//             ("output-path,o", po::value<std::string>(&outputData_.outputFilePath), "output file path")
//             ("output-name,s", po::value<std::string>(&outputData_.outputFileName), "output file name")
//             ("output-type,e", po::value<std::string>(&outputData_.outputFileType), "output file type (video, image, pointcloud)")
//         ;

//         po::variables_map vm;
//         po::store(po::parse_command_line(argc, argv, desc), vm);
//         po::notify(vm);

//         if (vm.count("help")) {
//             std::cout << desc << std::endl;
//             exit(1);
//         }
//     }

//     InputData inputData_;
//     OutputData outputData_;
// };

#include <cstring>
#include <iostream>
#include <map>
#include <string>

#pragma once

struct InputData {
  std::string filePath;
  std::string fileName;
  std::string fileType; // video, image, pointcloud
};

struct OutputData {
  std::string outputFilePath;
  std::string outputFileName;
  std::string outputFileType; // video, image, pointcloud
};

class InputParser {
public:
  InputParser(int argc, char *argv[]) { parseOptions(argc, argv); }

  InputData getInputData() const { return inputData_; }

  OutputData getOutputData() const { return outputData_; }

private:
  void parseOptions(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--input-path") == 0) {
        i++;
        inputData_.filePath = argv[i];
      } else if (strcmp(argv[i], "-n") == 0 ||
                 strcmp(argv[i], "--input-name") == 0) {
        i++;
        inputData_.fileName = argv[i];
      } else if (strcmp(argv[i], "-t") == 0 ||
                 strcmp(argv[i], "--input-type") == 0) {
        i++;
        inputData_.fileType = argv[i];
      } else if (strcmp(argv[i], "-o") == 0 ||
                 strcmp(argv[i], "--output-path") == 0) {
        i++;
        outputData_.outputFilePath = argv[i];
      } else if (strcmp(argv[i], "-s") == 0 ||
                 strcmp(argv[i], "--output-name") == 0) {
        i++;
        outputData_.outputFileName = argv[i];
      } else if (strcmp(argv[i], "-e") == 0 ||
                 strcmp(argv[i], "--output-type") == 0) {
        i++;
        outputData_.outputFileType = argv[i];
      } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
        i++;
        displayHelp(argc, argv);
      }
    }
  }

  void displayHelp(int argc, char *argv[]) {
    std::cout << "Usage: " << argv[0] << " [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "  -h, --help          Display this help message" << std::endl;
    std::cout << "  -p, --input-path   Input file path" << std::endl;
    std::cout << "  -n, --input-name   Input file name" << std::endl;
    std::cout
        << "  -t, --input-type   Input file type (video, image, pointcloud)"
        << std::endl;
    std::cout << "  -o, --output-path  Output file path" << std::endl;
    std::cout << "  -s, --output-name  Output file name" << std::endl;
    std::cout
        << "  -e, --output-type  Output file type (video, image, pointcloud)"
        << std::endl;
  }

  InputData inputData_;
  OutputData outputData_;
};
