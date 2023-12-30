# ImageSystemByQt
Qt图像处理系统，使用Opencv库，完成了图像的灰度变换、形态学操作、图像分割、图像滤波、边缘检测、人脸检测等功能。

## 功能

1. 图像的打开、显示、保存
2. 灰度图像处理
   1. RGB转灰度
   2. 显示灰度直方图
   3. 直方图均衡化
   4. 灰度变换
      1. 线性变换
      2. 非线性变换
         1. 对数变换
         2. 伽马变换
3. 形态学处理
   1. 腐蚀
   2. 膨胀
4. 图像分割
   1. 阈值分割
      1. 固定阈值
      2. 自定义阈值
   2. 区域生长
   3. 边缘分割
      1. Sobel算子
      2. Canny算子
5. 图像滤波
   1. 均值滤波
   2. 中值滤波
   3. 高斯滤波
6. 人脸检测

## 参考

- [MFC-Image](https://github.com/Mouseminar/MFC-Image)
  
- [MFC-ImageSystem](https://github.com/Mouseminar/MFC-Image)