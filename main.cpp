#include<iostream>
#include<opencv2\opencv.hpp>
#include<opencv2\highgui\highgui.hpp>

#include "imgoperate.h"

using namespace std;
using namespace cv;


int main() 
{
	string imgname = "E:/ZJU/data/rgb2.png";
	Mat img = imread(imgname, 1);
	ImgToolkit::ImageOperate newOp;
	uchar*** newImage;
	newImage = newOp.readImage(img);

	cout << newOp.img.channels<<" "<< newOp.img.height << endl;

	return 0;

}