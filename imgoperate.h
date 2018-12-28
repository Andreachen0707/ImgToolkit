#pragma once
#ifndef IMG_OPERATE_H
#define IMG_OPERATE_H

#include <stdio.h>
#include <uchar.h>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/calib3d/calib3d.hpp>

namespace ImgToolkit
{
	struct Image
	{
		int height;
		int width;
		int channels;
		uchar*** data;
	};
	class ImageOperate
	{
	public:
		Image img;
		ImageOperate();
		~ImageOperate();
		
		uchar*** readImage(cv::Mat& input);
		Image copyImgDeep(Image input);

		std::vector<int> computHist(uchar** input);
		uchar** convertImage(uchar*** input);

	//private:

	};

	


}


#endif
