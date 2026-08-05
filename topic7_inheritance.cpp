/*
 * Topic 7: Inheritance & Access Specifiers (protected)
 * Problem Set 7: Specialized Square Matrix
 * 
 * Problem Requirements:
 * 1. Modify Matrix class members from private to protected.
 * 2. Define derived class 'SquareMatrix' inheriting publicly from Matrix:
 *    - Constructor: SquareMatrix(int size) -> calls Matrix(size, size).
 *    - int getTrace() const -> Returns sum of main diagonal elements.
 *    - void makeIdentity() -> Sets diagonal elements to 1, others to 0.
 * 3. In main():
 *    - Instantiate SquareMatrix sq(3);
 *    - Turn it into an identity matrix and print it using cout << sq;
 *    - Output the trace of the matrix.
 */

#include<iostream>
using namespace std;

class Matrix
{
protected:
    int rows, cols;
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

// Defining a derived class SquareMatrix that publicly inherits from Matrix: class SquareMatrix : public Matrix
class SquareMatrix : public Matrix
{
public:
    // Constructor: SquareMatrix(int size) -> Calls Matrix(size, size).
    SquareMatrix(int size) : Matrix(size, size) {}
    // Member Function: int getTrace() const
    int getTrace() const
    {
        int trace = 0;
        for (int i=0; i<rows; i++)
        {
            trace += data[i][i];
        }
        return trace;
    }
    // Member Function: void makeIdentity()
    void makeIdentity()
    {
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<rows; j++)
            {
                if (i == j)
                    data[i][j] = 1;
                else
                    data[i][j] = 0;
            }
        }
    }
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
    // Instantiating a SquareMatrix sq(3);.
    SquareMatrix sq(3);

    // Calling sq.makeIdentity();.
    sq.makeIdentity();

    // Printing sq using cout << sq;.
    cout << sq;

    // Calculating and printing sq.getTrace() (should be 3 for a 3 x 3 identity matrix).
    cout << sq.getTrace();
	
	return 0;
}