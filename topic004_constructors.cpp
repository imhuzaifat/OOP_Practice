/*
 * Topic 4: Constructors & Destructors (RAII Pattern)
 * Problem Set 4: Dynamic Matrix Wrapper Class
 * 
 * Problem Requirements:
 * 1. Define a 'Matrix' class with private attributes:
 *    - int rows, cols
 *    - int** data (2D dynamic array)
 * 2. Implement public member functions:
 *    - Parameterized Constructor: Matrix(int r, int c) -> Allocates memory & zero-initializes.
 *    - Destructor: ~Matrix() -> Safely deallocates heap memory.
 *    - setElement(int r, int c, int value) -> Sets element with bounds checking.
 *    - getElement(int r, int c) const -> Gets element with bounds checking.
 *    - print() const -> Displays the matrix formatted.
 * 3. In main():
 *    - Instantiate a Matrix object, set values, print it, and let the destructor clean up.
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
    // Instantiating a Matrix object on the stack (e.g., 3 x 3)
    Matrix mat1(3,3);

    // Populating a few elements using setElement.
    mat1.setElement(1,1,45);    // Inbound Value
    mat1.setElement(0,2,67);    // Inbound Value
    mat1.setElement(2,1,95);    // Inbound Value
    mat1.setElement(2,3,32);    // Outbound Value

    // Displaying the matrix using print().
    mat1.print();

    return 0;
}