#include <cstdio>

#include <opencv2/opencv.hpp>
#include <opencv_lib.hpp>

#include "thermo.h"

int main() {
	cv::Mat src, dst;

	src = cv::imread("C:\\Users\\user\\Pictures\\diff.png", CV_LOAD_IMAGE_GRAYSCALE);
	thermo(src, dst);

	cv::imwrite("dst.png", dst);

	cv::imshow("src", src);
	cv::imshow("dst", dst);
	cv::waitKey(0);

	return 0;
}