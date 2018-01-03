# ThermoImage

グレイスケール画像をサーモグラフィのように着色するプログラム。  
輝度が低ければ黒、高ければ白に着色される。

## 例

元画像  
![src](readme/grad.png)

着色結果  
![dst](readme/grad-dst.png)

## 使用方法

```cpp
#include <opencv2/opencv.hpp>
#include "thermo.h"

int main() {
    cv::Mat src, dst;

    src = cv::imread(filename, CV_LOAD_IMAGE_GRAYSCALE);
    thermo(src, dst);

    return 0;
}
```

## 着色方法

以下の式を用いて各チャネルの値を決定している。  
![color](readme/color.png)
