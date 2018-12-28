#include "imgoperate.h"

using namespace std;

namespace ImgToolkit 
{
	ImageOperate::ImageOperate()
	{
	}


	ImageOperate::~ImageOperate()
	{
		if (img.data != NULL) {
			delete img.data;
		}
	}

	Image ImageOperate::copyImgDeep(Image input)
	{
		Image newImg;
		newImg.height = input.height;
		newImg.width = input.width;
		newImg.channels = input.channels;

		uchar*** data = new uchar**[newImg.height];
		for (int i = 0; i < img.height; i++)
		{
			for (int j = 0; j < img.width; j++)
			{
				data[i][j] = img.data[i][j];
			}
		}

		newImg.data = data;
		return newImg;

	}
	uchar*** ImageOperate::readImage(cv::Mat& input)
	{
		img.height = input.rows;
		img.width = input.cols;
		img.channels = input.channels();

		uchar*** output = new uchar**[input.rows];

			for (int i = 0; i < input.rows; i++)
			{
				output[i] = new uchar*[input.cols];
				for (int j = 0; j < input.cols; j++)
				{
					output[i][j] = new uchar[input.channels()];
					for (int k = 0; k < input.channels(); k++)
					{
						output[i][j][k] = uchar(input.at<cv::Vec3b>(i, j)[k]);
					}
				}
			}
		
		img.data = output;

		return output;

	}

	uchar** ImageOperate::convertImage(uchar*** input)
	{
		uchar** output = new uchar*[img.height];
		for (int i = 0; i < img.height; i++)
		{
			for (int j = 0; j < img.width; j++)
			{
				output[i][j] = int(0.299*double(input[i][j][2]) + 0.587*double(input[i][j][1]) + 0.114*double(input[i][j][0]));
			}
		}
		return output;
	}

	std::vector<int> ImageOperate::computHist(uchar** input)
	{
		vector<int> hist(256);
		for (int i = 0; i < img.height; i++)
		{
			for (int j = 0; j < img.width; j++)
			{
				int pos = input[i][j] % 255;
				hist[pos]++;
			}
		}
		return hist;

	}
}
