#include "thermo.h"

#include <cmath>

/// <summary>
/// 輝度を基にチャネルの色を決定する
/// </summary>
/// <param name="min">画像の輝度の最小値</param>
/// <param name="max">画像の輝度の最大値</param>
/// <param name="c">画素の輝度</param>
/// <param name="color">画素のポインタ</param>
void _thermo(int min, int max, int c, cv::Vec3b &color) {
	int value = c - min;
	int range = max - min + 1;

	int level = 6 * value / range;
	int mod = value - level * range / 6;
	double theta = 3 * CV_PI * mod / range;

	if (theta > CV_PI / 2)theta = CV_PI / 2;

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

	color[0] = round(b);
	color[1] = round(g);
	color[2] = round(r);
}

void thermo(cv::Mat &src, cv::Mat &dst) {
	int min = 256;
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
			if (sp[x] < min) {
				min = sp[x];
			}
		}
	}

	for (int y = 0; y < src.rows; y++) {
		sp = src.ptr(y);
		dp = dst.ptr<cv::Vec3b>(y);

		cv::Vec3b color;
		for (int x = 0; x < src.cols; x++) {
			_thermo(min, max, sp[x], color);
			dp[x] = color;
		}
	}

	printf("min:%d, max:%d\n", min, max);
}