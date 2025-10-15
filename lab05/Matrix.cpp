//
// Created by modin on 10/15/2025.
//

#include "Matrix.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <random>
#include <algorithm>

using namespace std;


Matrix::Matrix(int rows, int cols):mRows(rows),mCols(cols),mElements(mRows*mCols,0) {


}
Matrix::Matrix(const Matrix &other):mCols(other.mCols),mRows(other.mRows),mElements(other.mElements) {

}
Matrix::Matrix(Matrix &&other) noexcept:mRows(other.mRows),mCols(other.mCols),mElements(move(other.mElements)) {

}

Matrix &Matrix::operator=(const Matrix &other) {

    if (this != &other) {
        if(this->mRows!=other.mRows || this->mCols!=other.mCols){
            throw out_of_range("Nem egyenlo mereteuek");
        }
        copy(other.mElements.begin(), other.mElements.end(),this->mElements.begin());
    }
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept {
    if (this != &other) {
        mRows = other.mRows;
        mCols = other.mCols;
        mElements = move(other.mElements);
        other.mRows = 0;
        other.mCols = 0;
    }
    return *this;
}

void Matrix::fillMatrix(double value) {
    for (auto& e : mElements) {
        e = value;
    }
}

void Matrix::randomMatrix(int a, int b) {
    srand(time(0));
    for(int i=0;i<mRows*mCols;++i){
        double d=rand();
        d=d/RAND_MAX;
        mElements[i]=a+d*(b-a);
    }

//    random_device rd;
//    mt19937 gen(rd());
//    uniform_real_distribution<>dis(a,b);
//    for(auto& e:mElements){
//        e = dis(gen);
//    }

}
void Matrix::printMatrix(std::ostream &os) const {
    for(int i=0;i<this->mRows;++i){
        for(int j=0;j< this->mCols;++j){
            os<<setw(8)<<mElements[i*mCols+j]<<" ";
        }
        os<<endl;
    }
}
double *Matrix::operator[](int row) {
    return &mElements[row*mCols];
}

const double *Matrix::operator[](int row) const {
    return &mElements[row*mCols];
}
Matrix operator+(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw invalid_argument("Matrix dimensions must match for addition");
    }

    Matrix result(x.mRows, x.mCols);
    for (size_t i = 0; i < x.mElements.size(); ++i) {
        result.mElements[i] = x.mElements[i] + y.mElements[i];
    }

    return result;
}
Matrix operator*(const Matrix &x, const Matrix &y) {
    if (x.mRows != y.mRows || x.mCols != y.mCols) {
        throw invalid_argument("Matrix dimensions must match for addition");
    }

    Matrix result(x.mRows, x.mCols);
    for (int i = 0; i < x.mRows; ++i) {
        for (int j = 0; j < y.mCols; ++j) {
            double sum = 0.0;
            for (int k = 0; k < x.mCols; ++k) {
                sum += x.mElements[i * x.mCols + k] * y.mElements[k * y.mCols + j];
            }
            result.mElements[i * y.mCols + j] = sum;
        }
    }

    return result;
}

std::istream &operator>>(istream &is, Matrix &mat) {
    int rows, cols;
    is >> rows >> cols;

    mat.mRows = rows;
    mat.mCols = cols;
    mat.mElements.resize(rows * cols);

    for (int i = 0; i < rows * cols; ++i) {
        is >> mat.mElements[i];
    }

    return is;
}
std::ostream &operator<<(ostream &os, const Matrix &mat) {
    mat.printMatrix();
    return os;
}




















