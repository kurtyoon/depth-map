//
// Created by Kurt Yoon on 9/27/24.
//

#include "ImageLoader.h"
#include <opencv2/opencv.hpp>
#include <stdexcept>

cv::Mat ImageLoader::load_image(const std::string& file_path) {
    cv::Mat image = cv::imread(file_path, cv::IMREAD_GRAYSCALE);
    if (image.empty()) {
        throw std::runtime_error("이미지 로드 실패: " + file_path);
    }
    return image;
}

void ImageLoader::save_image(const cv::Mat& image, const std::string& file_path) {
    cv::imwrite(file_path, image);
}