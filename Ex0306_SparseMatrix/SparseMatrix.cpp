#include "SparseMatrix.h"

#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(int num_rows, int num_cols, int capacity)
{
	// TODO:
	terms_ = new MatrixTerm[capacity];

	num_rows_ = num_rows;
	num_cols_ = num_cols;
	capacity_ = capacity;
	num_terms_ = 0;
}

// 복사 생성자 (b를 복사)
SparseMatrix::SparseMatrix(const SparseMatrix &b)
{
	// TODO:
	terms_ = new MatrixTerm[b.capacity_];

	num_rows_ = b.num_rows_;
	num_cols_ = b.num_cols_;
	capacity_ = b.capacity_;
	num_terms_ = b.num_terms_;

	memcpy(terms_, b.terms_, sizeof(MatrixTerm) * num_terms_);
}

SparseMatrix::~SparseMatrix()
{
	// TODO:
	if (terms_)
		delete[] terms_;
}

void SparseMatrix::SetValue(int row, int col, float value)
{
	if (value == 0.0f)
		return; // value가 0이 아닌 term만 저장

	// TODO:
	// else
	// {
	// 	terms_[num_terms_].value = value;
	// 	terms_[num_terms_].row = row;
	// 	terms_[num_terms_].col = col;
	// 	num_terms_++;
	// }
	int key = row * num_cols_ + col;
	int i = 0;
	for (; i < num_terms_; i++)
	{
		int key_i = terms_[i].row * num_cols_ + terms_[i].col;

		if (key == key_i)
		{
			terms_[i].col = col;
			terms_[i].row = row;
			terms_[i].value = value;
			// break;
			return;
		}

		else if (key < key_i)
			break;
	}

	// 삽입정렬처럼 끝까지 하나씩 밀고 추가
	assert(capacity_ > num_terms_);
	num_terms_++;

	for (int j = num_terms_ - 1; j > i; j--)
		terms_[j] = terms_[j - 1];
	terms_[i].row = row;
	terms_[i].col = col;
	terms_[i].value = value;
}

float SparseMatrix::GetValue(int row, int col) const // 맨 뒤의 const는 함수 안에서 멤버 변수의 값을 바꾸지 않겠다는 의미
{
	// TODO: key = col + num_cols * row;
	// for (int i = 0; i < num_terms_; i++)
	// {
	// 	if (terms_[i].row == row && terms_[i].col == col)
	// 		return terms_[i].value;
	// }
	// return 0.0f;

	int key = row * num_cols_ + col;
	for (int i = 0; i < num_terms_; i++)
	{
		int key_i = terms_[i].row * num_cols_ + terms_[i].col;

		if (key == key_i)
			return terms_[i].value;
	}

	return 0.0f;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix temp(num_cols_, num_rows_, capacity_); // num_cols_, num_rows_ 순서 주의

	// TODO:
	for (int row = 0; row < num_rows_; row++)
	{
		for (int col = 0; col < num_cols_; col++)
		{
			temp.SetValue(col, row, GetValue(row, col));
		}
	}

	return temp;
}

void SparseMatrix::PrintTerms()
{
	for (int i = 0; i < num_terms_; i++)
		cout << "(" << terms_[i].row
			 << ", " << terms_[i].col
			 << ", " << terms_[i].value
			 << ")" << endl;
}

void SparseMatrix::Print()
{
	for (int r = 0; r < num_rows_; r++)
	{
		for (int c = 0; c < num_cols_; c++)
			cout << GetValue(r, c) << " ";
		cout << endl;
	}
}
