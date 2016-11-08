#include "thermo.h"

#include <cmath>

void _thermo(int min, int max, int c, cv::Vec3b &color) {
	int level = 6 * c / max;
	int mod = (6 * c) % max;
	double theta = mod / (12.0 * max) * CV_PI;

	int r, g, b;
	switch (level)
	{
	case 0:
		r = 0;
		g = 0;
		b = 255 * sin(theta);
		break;
	case 1:
		r = 0;
		g = 255 * sin(theta);
		b = 255;
		break;
	case 2:
		r = 0;
		g = 255;
		b = 255 * cos(theta);
		break;
	case 3:
		r = 255 * sin(theta);
		g = 255;
		b = 0;
		break;
	case 4:
		r = 255;
		g = 255 * cos(theta);
		b = 0;
		break;
	case 5:
		r = 255;
		g = 255 * sin(theta);
		b = 255 * sin(theta);
		break;
	default:
		r = 255;
		g = 255;
		b = 255;
		break;
	}

	color[0] = b;
	color[1] = g;
	color[2] = r;
}

void thermo(cv::Mat &src, cv::Mat &dst) {
	int max = 0;
	uchar *sp;
	cv::Vec3b *dp;
	dst.create(src.rows, src.cols, CV_8UC3);

	for (int y = 0; y < src.rows; y++) {
		sp = src.ptr(y);
		for (int x = 0; x < src.cols; x++) {
			if (sp[x] > max) {
				max = sp[x];
			}
		}
	}

	for (int y = 0; y < src.rows; y++) {
		sp = src.ptr(y);
		dp = dst.ptr<cv::Vec3b>(y);

		cv::Vec3b color;
		for (int x = 0; x < src.cols; x++) {
			_thermo(0, max, sp[x], color);
			dp[x] = color;
		}
	}

	printf("max:%d\n", max);
}