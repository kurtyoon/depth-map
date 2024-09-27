//
// Created by Kurt Yoon on 9/27/24.
//

#ifndef STEREOMATCHER_H
#define STEREOMATCHER_H

#include <vector>
#include <unordered_map>
#include <string>

class StereoMatcher {
  private:
    int max_disparity;
    double lambda;
    std::unordered_map<std::string, double> likelihood_cache;

  public:
    StereoMatcher(int max_disp, double lambda_val);
    double calculate_likelihood(unsigned char left_pixel, unsigned char right_pixel);
    double calculate_prior(int disparity_1, int disparity_2);
    std::vector<std::vector<int>> compute_disparity_map(
        const std::vector<std::vector<unsigned char>>& left_image,
        const std::vector<std::vector<unsigned char>>& right_image
    );
};

#endif //STEREOMATCHER_H
