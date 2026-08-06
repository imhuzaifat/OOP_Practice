/*
 * Topic 8: Polymorphism & Virtual Functions
 * Problem Set 8: Polymorphic Matrix Printing & Virtual Cleanup
 * 
 * Problem Requirements:
 * 1. Mark ~Matrix() as virtual to ensure proper cleanup via base pointers.
 * 2. Mark Matrix::print() as virtual.
 * 3. Override print() in SquareMatrix with the 'override' keyword:
 *    - Output a header ("--- Square Matrix (NxN) ---") before grid contents.
 * 4. In main():
 *    - Instantiate an array of Matrix* pointers holding both Matrix and SquareMatrix objects.
 *    - Polymorphically call print() on each pointer in a loop.
 *    - Delete objects via base pointers to verify virtual destructor execution.
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
	// Marking ~Matrix() as virtual.
    virtual ~Matrix()
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
	// Marking void print() const virtual
    virtual void print() const
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
	void print() const override
    {
		// Printing a Header Line
		cout << "--- Square Matrix (" << rows << "x" << rows << ") ---" << endl;
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
	Matrix* matrices[2];

    matrices[0] = new Matrix(2, 3);

    SquareMatrix* sq = new SquareMatrix(3);
    sq->makeIdentity();
    matrices[1] = sq;

    for (int i=0; i<2; i++)
        matrices[i]->print();

    for (int i=0; i<2; i++)
        delete matrices[i];
    
    return 0;
}