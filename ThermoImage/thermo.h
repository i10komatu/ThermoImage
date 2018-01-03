#pragma once

#include <opencv2/opencv.hpp>

/// <summary>
/// グレイスケール画像をサーモグラフィ風に着色する
/// </summary>
/// <param name="src">グレイスケール画像</param>
/// <param name="dst">フルカラー画像</param>
void thermo(cv::Mat &src, cv::Mat &dst);