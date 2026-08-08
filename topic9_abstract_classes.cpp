/*
 * Topic 9: Abstract Classes & Pure Virtual Functions
 * Problem Set 9: Abstract Base Matrix Contract
 * 
 * Problem Requirements:
 * 1. Define Abstract Base Class 'AbstractMatrix' with pure virtual functions:
 *    - virtual void print() const = 0;
 *    - virtual int getElement(int r, int c) const = 0;
 * 2. Inherit Matrix from AbstractMatrix and provide full overrides.
 * 3. In main():
 *    - Demonstrate that AbstractMatrix cannot be directly instantiated.
 *    - Demonstrate dynamic dispatch using AbstractMatrix* base pointers.
 */

#include<iostream>
using namespace std;

class AbstractMatrix
{
protected:
    int rows, cols;
    int** data;
public:
    AbstractMatrix(int r, int c) : rows(r), cols(c)
    {
        data = new int*[rows];
    for (int i=0; i<rows; i++)
    {
        data[i] = new int[cols];
        for (int j=0; j<cols; j++)
        {
            data[i][j] = 0;
        }
    }
    }
    AbstractMatrix(const AbstractMatrix& other)
    {
        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for (int i=0; i<rows; i++)
        {
            data[i] = new int[cols];
            for (int j=0; j<cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }
    }
    virtual ~AbstractMatrix()
    {
    for (int i=0; i<rows; i++)
        delete[] data[i];
    
    delete[] data;
    data = nullptr;
    }
    virtual void print() const = 0;
    virtual int getElement(int r, int c) const = 0;
};

class Matrix : public AbstractMatrix
{
public:
    Matrix(int r, int c) : AbstractMatrix(r,c) {}
    Matrix(const Matrix& other) : AbstractMatrix(other) {}
    Matrix& operator=(const Matrix& other)
    {
        if (this == &other)
            return *this;

        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        data = new int*[rows];
        for (int i = 0; i < rows; i++)
        {
            data[i] = new int[cols];
            for (int j = 0; j < cols; j++)
            {
                data[i][j] = other.data[i][j];
            }
        }

        return *this;
    }
    Matrix operator+(const Matrix& other) const
    {
        if (this->rows != other.rows || this->cols != other.cols)
        {
            cerr << "The Two Matrices don't have same dimensions!" << endl;
            return Matrix(0, 0);
        }

        Matrix temp(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return temp;
    }
    bool operator==(const Matrix& other) const
    {
        if (rows != other.rows || cols != other.cols)
            return false;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (data[i][j] != other.data[i][j])
                    return false;
            }
        }
        return true;
    }
    void setElement(int r, int c, int value)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            cout << r << "x" << c << " is out of bound!" << endl;
        else
            data[r][c] = value;
    }
    int getElement(int r, int c) const override
    {
        if (r<rows && c<cols)
            return data[r][c];
        return -1;
    }
    void print() const override
    {
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
            {
                cout << data[i][j] << '\t';
            }
            cout << endl;
        }
    }
    friend ostream& operator<<(ostream& os, const Matrix& mat);
};

ostream& operator<<(ostream& os, const Matrix& mat)
{
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            os << mat.data[i][j] << '\t';
        }
        os << endl;
    }
    return os;
}

int main()
{
    // AbstractMatrix am(2, 2);
    // Can't Instantiate Abstract Matrix

    AbstractMatrix* ptr = new Matrix(2, 2);
    ptr->print();

    delete ptr;
    ptr = nullptr;

    return 0;
}