/*
 * Topic 6: Operator Overloading
 * Problem Set 6: Matrix Arithmetic & Stream Printing
 * 
 * Problem Requirements:
 * 1. Overload operator+ to perform element-wise addition of two matrices.
 * 2. Overload operator== to check if two matrices have identical dimensions and values.
 * 3. Overload friend operator<< to enable direct cout << matrix printing.
 * 4. In main():
 *    - Add two matrices: Matrix mat3 = mat1 + mat2;
 *    - Print result using cout << mat3;
 *    - Test equality using if (mat1 == mat2).
 */

#include<iostream>
using namespace std;

class Matrix
{
private:
    int rows;
    int cols;
    int** data;
public:
    Matrix(int r, int c) : rows(r), cols(c)
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
    Matrix(const Matrix& other)
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
    Matrix& operator=(const Matrix& other)
    {
        // 1. Guard against self-assignment (e.g., mat1 = mat1)
        if (this == &other)
            return *this;

        // 2. Clean up existing memory in 'this' object
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;

        // 3. Perform Deep Copy
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

        // 4. Return *this to enable chained assignments (e.g., a = b = c)
        return *this;
    }
    Matrix operator+(const Matrix& other) const
    {
        if (this->rows != other.rows || this->cols != other.cols)
        {
            cerr << "The Two Matrices don't have same dimensions!" << endl;
            return Matrix(0, 0);
        }

        Matrix temp(rows, cols); // Create a fresh matrix to store the result
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                temp.data[i][j] = this->data[i][j] + other.data[i][j];
            }
        }
        return temp; // Return the new result object
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
    ~Matrix()
    {
    for (int i=0; i<rows; i++)
        delete[] data[i];
    
    delete[] data;
    data = nullptr;
    }
    void setElement(int r, int c, int value)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols)
            cout << r << "x" << c << " is out of bound!" << endl;
        else
            data[r][c] = value;
    }
    int getElement(int r, int c) const
    {
        if (r<rows && c<cols)
            return data[r][c];
        return -1;
    }
    void print() const
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
    // Creating mat1 and mat2 (both 2 x 2) and filling them with numbers.
    Matrix mat1(2,2), mat2(2,2);
    mat1.setElement(0,0, 75);
    mat1.setElement(0,1, 42);
    mat1.setElement(1,0, 53);
    mat1.setElement(1,1, 20);
    mat2.setElement(0,0, 49);
    mat2.setElement(0,1, 99);
    mat2.setElement(1,0, 51);
    mat2.setElement(1,1, 65);

    // Computing Matrix mat3 = mat1 + mat2;
    Matrix mat3 = mat1 + mat2;

    // Printing mat3 using cout << mat3; instead of print().
    cout << mat3;

    mat1.setElement(0,0, 75);
    mat1.setElement(0,1, 42);
    mat1.setElement(1,0, 53);
    mat1.setElement(1,1, 20);
    mat2.setElement(0,0, 75);
    mat2.setElement(0,1, 42);
    mat2.setElement(1,0, 53);
    mat2.setElement(1,1, 20);
    // Testing equality: if (mat1 == mat2) and printing whether they are equal.
    if (mat1 == mat2)
        cout << "mat1 == mat2" << endl;

    return 0;
}