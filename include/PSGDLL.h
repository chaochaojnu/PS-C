// pch.h: 这是预编译标头文件。
// 下方列出的文件仅编译一次，提高了将来生成的生成性能。
// 这还将影响 IntelliSense 性能，包括代码完成和许多代码浏览功能。
// 但是，如果此处列出的文件中的任何一个在生成之间有更新，它们全部都将被重新编译。
// 请勿在此处添加要频繁更新的文件，这将使得性能优势无效。

#ifndef PCH_H
#define PCH_H

// 添加要在此处预编译的标头
//#include "framework.h"
#include <opencv2/core.hpp>
#include <iostream>
#include <vector>
#include <string>
extern "C" _declspec(dllexport) cv::Mat getImages(std::string src_path, std::string src);

extern "C" _declspec(dllexport) int lightCorrect(cv::Mat& base_imarray, double lightCircle, double lightHeight, double cameraHeight, std::string str, int a, int b, cv::Mat& Ep, cv::Mat& angleMap_1, cv::Mat& angleMap_2);

extern "C" _declspec(dllexport) int preprocess(cv::Mat& Ori_imarray, cv::Rect roi, int thres, cv::Mat& Ep, cv::Mat& Ia, cv::Mat& imarray);

extern "C" _declspec(dllexport) int getNormalVec(cv::Mat& imarray, cv::Mat& Ia, cv::Mat& lightCor_1, cv::Mat& lightCor_2, std::string str, cv::Mat& albedoImage, cv::Mat& surfaceNormals);

extern "C" _declspec(dllexport) int getSurface(cv::Mat& surfaceNormals, cv::Mat& heightMap);

//extern "C" _declspec(dllexport) int display_heightmap(cv::Mat& heightMap);

extern "C" _declspec(dllexport) void imagereconstruction(cv::Mat& base_imarray, cv::Mat& Ori_imarray, double resolution, double lightCircle, double lightHeight, double cameraHeight, double Image_rows, double Image_cols, cv::Rect Roi, cv::Mat& albedoImage, cv::Mat& surfaceNormals, cv::Mat& heightMap);



#endif //PCH_H
