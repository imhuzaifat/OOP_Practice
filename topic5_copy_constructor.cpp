/*
 * Topic 5: Copy Constructors & The Rule of Three
 * Problem Set 5: Deep Copy Matrix Demonstration
 * 
 * Problem Requirements:
 * 1. Implement a custom Copy Constructor:
 *    - Matrix(const Matrix& other)
 *    - Performs a DEEP COPY by allocating new heap memory and copying values.
 * 2. In main():
 *    - Instantiate 'mat1' (2x2) and populate it with values.
 *    - Create 'mat2' using the copy constructor: Matrix mat2 = mat1;
 *    - Modify mat2 using setElement().
 *    - Print both matrices to confirm mat1 remains unchanged (proving independent memory allocation).
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
    operator=(const Matrix& other)
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
};

int main()
{
    // Creating a Matrix mat1(2, 2);
    Matrix mat1(2, 2);

    // Populating mat1 with values: mat1.setElement(0,0, 10); mat1.setElement(0,1, 20);
    mat1.setElement(0,0, 10);
    mat1.setElement(0,1, 20);

    // Creating mat2 as a copy using the copy constructor: Matrix mat2 = mat1;
    Matrix mat2 = mat1;
    // or we can do: Matrix mat2(mat1);

    // Modifying an element in mat2: mat2.setElement(0,0, 999);
    mat2.setElement(0,0, 999);

    // Printing both mat1 and mat2
    cout << "Matrix 1: " << endl;
    mat1.print();
    cout << "Matrix 2: " << endl;
    mat2.print();

    return 0;
}