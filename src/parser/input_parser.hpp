#include <iostream>
#include <string>
#include <map>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class InputParser {
public:
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

    InputParser(int argc, char* argv[]) {
        parseOptions(argc, argv);
    }

    InputData getInputData() const {
        return inputData_;
    }

    OutputData getOutputData() const {
        return outputData_;
    }

private:
    void parseOptions(int argc, char* argv[]) {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "produce help message")
            ("input-path,p", po::value<std::string>(&inputData_.filePath), "input file path")
            ("input-name,n", po::value<std::string>(&inputData_.fileName), "input file name")
            ("input-type,t", po::value<std::string>(&inputData_.fileType), "input file type (video, image, pointcloud)")
            ("output-path,o", po::value<std::string>(&outputData_.outputFilePath), "output file path")
            ("output-name,s", po::value<std::string>(&outputData_.outputFileName), "output file name")
            ("output-type,e", po::value<std::string>(&outputData_.outputFileType), "output file type (video, image, pointcloud)")
        ;

        po::variables_map vm;
        po::store(po::parse_command_line(argc, argv, desc), vm);
        po::notify(vm);

        if (vm.count("help")) {
            std::cout << desc << std::endl;
            exit(1);
        }
    }

    InputData inputData_;
    OutputData outputData_;
};
