#include <opencv2/opencv.hpp>
#include <iostream>


int main(int argc, char** argv) {
    std::cout << "test opencv" << std::endl;   

    cv::Mat z = cv::Mat::zeros(3, 3, CV_8UC1);

    std::cout << z << std::endl;
}
