# ThermoImage

グレイスケール画像をサーモグラフィのように着色するプログラム。  
輝度が低ければ黒、高ければ白に着色される。

## 例

元画像  
![src](readme/grad.png)

着色結果  
![dst](readme/grad-dst.png)

## 着色方法

以下の式を用いて各チャネルの値を決定している。  
![color](readme/color.png)
