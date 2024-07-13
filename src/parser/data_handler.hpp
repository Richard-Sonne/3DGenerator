#include "input_parser.hpp"
#include <fstream>
#include <memory>
#include <string>

#pragma once

class DataHandler {
public:
  DataHandler(const InputData &inputData) : inputData_(inputData) {
    readData();
  }

  const OutputData &getOutputData() const { return outputData_; }

private:
  void readData() {
    if (inputData_.fileType == "image") {
      readImage();
    } else if (inputData_.fileType == "video") {
      readVideo();
    } else if (inputData_.fileType == "pointcloud") {
      readPointCloud();
    }
  }

  void readImage() {}

  void readVideo() {}

  void readPointCloud() {}

  InputData inputData_;
  OutputData outputData_;
};
