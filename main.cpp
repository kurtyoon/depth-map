#include "core/StereoMatcher.h"
#include "usecase/DepthMapCalculator.h"
#include "infrastructure/ImageLoader.h"

int main() {
    try {
        ImageLoader image_loader;

        cv::Mat left_image = image_loader.load_image("../resources/left_image.jpg");
        cv::Mat right_image = image_loader.load_image("../resources/right_image.jpg");

        StereoMatcher matcher(64, 0.1);

        DepthMapCalculator calculator(matcher);

        calculator.calculate_depth_map(left_image, right_image, "../resources/depth_map.jpg");

        std::cout << "Depth map 생성 완료!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "오류 발생: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
