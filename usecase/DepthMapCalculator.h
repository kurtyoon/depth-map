//
// Created by Kurt Yoon on 9/27/24.
//

#ifndef DEPTHMAPCALCULATOR_H
#define DEPTHMAPCALCULATOR_H

#include <opencv2/opencv.hpp>
#include <vector>
#include "../core/StereoMatcher.h"

class DepthMapCalculator {
  private:
    StereoMatcher matcher;

  public:
  DepthMapCalculator(StereoMatcher stereo_matcher);
  std::vector<std::vector<unsigned char>> mat_to_vector(const cv::Mat& image);
  void calculate_depth_map(const cv::Mat& left_image, const cv::Mat& right_image, const std::string& output_file);
};

#endif //DEPTHMAPCALCULATOR_H
