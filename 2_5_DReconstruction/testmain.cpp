#include <iostream>
#include <opencv2\opencv.hpp>
#include <math.h>
#include <PSGDLL.h>


using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	for (int i = 1; i < 2; i++)
	{
		//�궨ͼ��·��������ͼ��·��,������
		string light_orignal_path = "D:\\desktop\\1\\";
		string image_orignal_path = "D:\\desktop\\2\\" + to_string(i) + "\\";
		Mat base_imarray = getImages(light_orignal_path, "standard");
		Mat Ori_imarray = getImages(image_orignal_path, "4dir");

		//ԭͼ�Ƿ�Ҫ��С��Ĭ��Ϊ1����С
		int smallflag = 1;
		resize(base_imarray, base_imarray, Size(base_imarray.cols / smallflag, base_imarray.rows / smallflag), 0, 0, INTER_LINEAR);
		resize(Ori_imarray, Ori_imarray, Size(Ori_imarray.cols / smallflag, Ori_imarray.rows / smallflag), 0, 0, INTER_LINEAR);

		//��ϳɵ�roi����
		Rect src_roi = Rect(0, 0, 1000,1000);

		//�����������
		Mat albedoImage = Mat::zeros(src_roi.height, src_roi.width, CV_32FC1);
		Mat surfaceNormals = Mat::zeros(src_roi.height, src_roi.width, CV_32FC3);
		Mat heightMap = Mat::zeros(src_roi.height, src_roi.width, CV_32FC1);

		imagereconstruction(base_imarray, Ori_imarray, 0.0197, 70, 60, 105, base_imarray.rows, base_imarray.cols, src_roi, albedoImage, surfaceNormals, heightMap);

		//������ͼ
		imwrite("..\\resultimage\\" + to_string(i) + "-heightMap.jpg", heightMap);
		Mat heightcolorMap;
		applyColorMap(heightMap, heightcolorMap, COLORMAP_JET);//red
		imwrite("..\\resultimage\\" + to_string(i) + "-heightcolorMap.jpg", heightcolorMap);
		cout << to_string(i) << " - finish�� " << endl;
	}
	return 0;
}