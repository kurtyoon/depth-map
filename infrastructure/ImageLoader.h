//
// Created by Kurt Yoon on 9/27/24.
//

#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include <opencv2/opencv.hpp>
#include <string>

class ImageLoader {
  public:
    cv::Mat load_image(const std::string& file_path);
    void save_image(const cv::Mat& image, const std::string& file_path);
};

#endif //IMAGELOADER_H
