//
// Created by Kurt Yoon on 9/27/24.
//

#include "StereoMatcher.h"
#include <cmath>
#include <limits>

StereoMatcher::StereoMatcher(int max_disp, double lambda_val) : max_disparity(max_disp), lambda(lambda_val) {}

double StereoMatcher::calculate_likelihood(unsigned char left_pixel, unsigned char right_pixel) {
    std::string key = std::to_string(left_pixel) + "_" + std::to_string(right_pixel);

    if (likelihood_cache.find(key) != likelihood_cache.end()) {
        return likelihood_cache[key];
    }

    double result = std::abs(static_cast<int>(left_pixel) - static_cast<int>(right_pixel));
    likelihood_cache[key] = result;

    return result;
}

double StereoMatcher::calculate_prior(int disparity_1, int disparity_2) {
    return std::abs(disparity_1 - disparity_2);
}

std::vector<std::vector<int>> StereoMatcher::compute_disparity_map(const std::vector<std::vector<unsigned char>>& left_image,
                                                                   const std::vector<std::vector<unsigned char>>& right_image) {
    int rows = left_image.size();
    int cols = left_image[0].size();

    std::vector<std::vector<int>> disparity_map(rows, std::vector<int>(cols, 0));

    for (int y = 0; y < rows; ++y) {
        for (int x = 0; x < cols; ++x) {
            double min_energy = std::numeric_limits<double>::max();
            int best_disparity = 0;

            for (int d = 0; d < max_disparity; ++d) {
                if (x - d < 0) continue;

                double likelihood = calculate_likelihood(left_image[y][x], right_image[y][x - d]);

                double prior = 0.0;
                if (x > 0) {
                    prior = calculate_prior(disparity_map[y][x - 1], d);
                }

                double energy = likelihood + lambda * prior;

                if (energy < min_energy) {
                    min_energy = energy;
                    best_disparity = d;
                }
            }

            disparity_map[y][x] = best_disparity;
        }
    }

    return disparity_map;
}
