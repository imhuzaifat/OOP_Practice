#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <exception>

class MatrixException : public std::exception {
private:
    std::string message;
public:
    MatrixException(std::string s) : message(s) {}
    const char* what() const noexcept override { return message.c_str(); }
};

class Matrix {
private:
    int rows, cols;
    int** data;
public:
    Matrix(int r, int c);
    ~Matrix();
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    void setElement(int r, int c, int value);
    int getElement(int r, int c) const;
    void print() const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
};

#endif // MATRIX_H