//
// Created by Kurt Yoon on 9/27/24.
//

#include "DepthMapCalculator.h"

DepthMapCalculator::DepthMapCalculator(StereoMatcher stereo_matcher) : matcher(stereo_matcher) {}

std::vector<std::vector<unsigned char>> DepthMapCalculator::mat_to_vector(const cv::Mat& image) {
    std::vector<std::vector<unsigned char>> result(image.rows, std::vector<unsigned char>(image.cols));
    for (int y = 0; y < image.rows; ++y) {
        for (int x = 0; x < image.cols; ++x) {
            result[y][x] = image.at<unsigned char>(y, x);
        }
    }
    return result;
}

void DepthMapCalculator::calculate_depth_map(const cv::Mat& left_image, const cv::Mat& right_image, const std::string& output_file) {
    auto left_vec = mat_to_vector(left_image);
    auto right_vec = mat_to_vector(right_image);

    auto disparity_map = matcher.compute_disparity_map(left_vec, right_vec);

    cv::Mat depth_map(left_image.size(), CV_8U);
    for (int y = 0; y < depth_map.rows; ++y) {
        for (int x = 0; x < depth_map.cols; ++x) {
            depth_map.at<unsigned char>(y, x) = static_cast<unsigned char>(disparity_map[y][x]);
        }
    }

    cv::imwrite(output_file, depth_map);
}
