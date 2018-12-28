#pragma once
#ifndef IMG_OPERATE_H
#define IMG_OPERATE_H

#include "core/matrix.h"
#include <stdio.h>
#include <uchar.h>
#include <vector>
#include <opencv2\opencv.hpp>

namespace ImgToolkit
{
	struct Image
	{
		int height;
		int width;
		int channels;
		int*** data;
	};
	class ImageOperate
	{
	public:
		Image img;
		ImageOperate();
		~ImageOperate();
		
		int*** readImage(cv::Mat input);
		Image copyImgDeep(Image input);

		int** convertImage(int*** input);
		vector<int> computeHist(int** input);

	private:

	};

	ImageOperate::ImageOperate()
	{
		Image img;
	}

	ImageOperate::~ImageOperate()
	{
		if (img.data != NULL) {
			delete img.data;
		}
	}


}


#endif
