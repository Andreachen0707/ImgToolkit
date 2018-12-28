#include "imgoperate.h"

using namespace std;

namespace ImgToolkit 
{
	Image ImageOperate::copyImgDeep(Image input)
	{
		Image newImg;
		newImg.height = input.height;
		newImg.width = input.width;
		newImg.channels = input.channels;

		int*** data = new int**[newImg.height];
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
	int*** ImageOperate::readImage(cv::Mat input)
	{
		img.height = input.rows;
		img.width = input.cols;
		img.channels = input.channels;

		int*** output = new int**[input.rows];
		if (img.channels == 1) 
		{
			for (int i = 0; i < input.rows; i++)
			{
				for (int j = 0; j < input.cols; j++)
				{
					output[i][j][0] = input.at<uchar>(i, j);
				}
			}
		}
		else 
		{
			for (int i = 0; i < input.rows; i++)
			{
				for (int j = 0; j < input.cols; j++)
				{
					int b = input.at<Vec3b>(i, j)[0];
					int g = input.at<Vec3d>(i, j)[1];
					int r = input.at<Vec3d>(i, j)[2];


					output[i][j][0] = b;
					output[i][j][1] = g;
					output[i][j][2] = r;
				}
			}
			

		}
		
		img.data = output;

		return output;

	}

	int** ImageOperate::convertImage(int*** input)
	{
		int** output = new int*[img.height];
		for (int i = 0; i < img.height; i++)
		{
			for (int j = 0; j < img.width; j++)
			{
				output[i][j] = int(0.299*double(input[i][j][2]) + 0.587*double(input[i][j][1]) + 0.114*double(input[i][j][0]));
			}
		}
		return output;
	}

	vector<int> ImageOperate::computeHist(int** input)
	{
		vector<int> hist(256);
		for (int i = 0; i < img.height; i++)
		{
			for (int j = 0; j < img.width; j++)
			{
				int pos = input[i][j] % 256;
				hist[pos]++;
			}
		}
		return hist;

	}
}
