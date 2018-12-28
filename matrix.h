#ifndef MATRIX_H
#define MATRIX_H
#pragma once
#include <stdio.h>
#include <uchar.h>
#include <opencv\cv.h>


using namespace std;


namespace ImgToolkit 
{

	class Matrix
	{
	public:
		Matrix();
		Matrix(int rows, int cols, int channels);
		~Matrix();

		void Matrix::newMatrix(int _rows, int _cols, int _channels);



	private:
		void Matrix::release();

	};

	Matrix::Matrix()
	{
	}

	Matrix::Matrix(int rows, int cols, int channels)
	{
		newMatrix(rows, cols, channels);
	}

	Matrix::~Matrix()
	{
	}

	void Matrix::newMatrix(int _rows, int _cols, int _channels)
	{
		assert(_rows * _cols * _channels != 0);

		flags = (DataType<_Tp>::depth << 8) | _channels;
		esize_ = sizeof(_Tp) * _channels;

		rows_ = _rows;
		cols_ = _cols;
		step_ = static_cast<int>(_cols * esize_);
		size_ = static_cast<size_t>(_rows * _cols);

		// Free memory
		release();

		// Alloc memory.
		datastart = ptr_ = reinterpret_cast<uint8_t*>(new _Tp[size_ * _channels]);
		dataend = ptr_ + size_ * esize_;

		// Reference counter.
		refcount = new int(1);
	}


	void Matrix::release()
	{
		if (refcount && refAdd(refcount, -1) == 1) {
			delete[] reinterpret_cast<_Tp *>(ptr_);
			ptr_ = datastart = dataend = nullptr;

			delete refcount;
			refcount = nullptr;
		}
	}

}


#endif
