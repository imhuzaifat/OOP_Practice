#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int r, int c) : rows(r), cols(c) {
    if (r <= 0 || c <= 0) throw MatrixException("Invalid Matrix Dimensions");
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols]{0};
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < rows; i++) delete[] data[i];
    delete[] data;
    data = nullptr;
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++) data[i][j] = other.data[i][j];
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;
    for (int i = 0; i < rows; i++) delete[] data[i];
    delete[] data;

    rows = other.rows;
    cols = other.cols;
    data = new int*[rows];
    for (int i = 0; i < rows; i++) {
        data[i] = new int[cols];
        for (int j = 0; j < cols; j++) data[i][j] = other.data[i][j];
    }
    return *this;
}

void Matrix::setElement(int r, int c, int value) {
    if (r < 0 || r >= rows || c < 0 || c >= cols) throw MatrixException("Out of Bounds");
    data[r][c] = value;
}

int Matrix::getElement(int r, int c) const {
    if (r < 0 || r >= rows || c < 0 || c >= cols) throw MatrixException("Out of Bounds");
    return data[r][c];
}

void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) cout << data[i][j] << '\t';
        cout << endl;
    }
}

ostream& operator<<(ostream& os, const Matrix& mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) os << mat.data[i][j] << '\t';
        os << endl;
    }
    return os;
}