/*
 * Topic 11: Exception Handling & Custom Exceptions
 * Problem Set 11: Robust Matrix with Custom Exceptions
 * 
 * Problem Requirements:
 * 1. Define custom MatrixException class inheriting from std::exception.
 * 2. Throw MatrixException on invalid constructor parameters (r <= 0, c <= 0).
 * 3. Throw MatrixException on out-of-bounds access in setElement / getElement.
 * 4. Throw MatrixException on dimension mismatch in operator+.
 * 5. In main():
 *    - Wrap risky code in try-catch blocks.
 *    - Trigger and gracefully handle invalid allocation and out-of-bounds exceptions.
 */

 #include<iostream>
using namespace std;

template<typename T>
class Matrix;

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& mat);

template<typename T>
class Matrix
{
protected:
    int rows, cols;
    T** data;
public:
    Matrix(int r, int c);   // Constructor
    ~Matrix();  // Destructor

    Matrix(const Matrix& other);    // Copy Constructor

    // Operator Functions
    Matrix<T>& operator=(const Matrix<T>& other);
    Matrix<T> operator+(const Matrix<T>& other) const;
    bool operator==(const Matrix<T>& other) const;
    friend ostream& operator<<<>(ostream& os, const Matrix<T>& mat);

    // Member Functions
    void setElement(int r, int c, T value);
    T getElement(int r, int c) const;
    void print() const;
};

class MatrixException : public exception
{
private:
    string message;
public:
    MatrixException(int r, int c)
    {
        message = "Index out of bounds: [" + to_string(r) + "][" + to_string(c) + "]";
    }
    MatrixException(string s) : message(s) {}

    const char* what() const noexcept override
    {
        return message.c_str();
    }
};

int main()
{
    try
    {
        Matrix<int> intMat(2, 2);
        intMat.setElement(0,0, 19);
        intMat.setElement(0,1, 64);
        intMat.setElement(1,0, 57);
        intMat.setElement(1,1, 38);
        cout << "intMat:" << endl << intMat;

        Matrix<double> doubleMat(2, 2);
        doubleMat.setElement(0,0, 3.14);
        doubleMat.setElement(0,1, 2.71);
        doubleMat.setElement(1,0, 1.41);
        doubleMat.setElement(1,1, 0.57);
        cout << "doubleMat:" << endl << doubleMat;

        //Test 1:
        Matrix<int> badMat(0, -2);

        // Test 2:
        intMat.getElement(5, 5);
        
        return 0;
    }
    catch (const MatrixException& e)
    {
        cerr << "Matrix Error: " << e.what() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Other Standard Exception: " << e.what() << endl;
    }
    catch (...)
    {
        cerr << "Unknown Exception Type" << endl;
    }
}

template<typename T>
Matrix<T>::Matrix(int r, int c) : rows(r), cols(c)
{
    if (r<=0 || c<=0)   throw MatrixException("Invalid Matrix Dimension");

    data = new T*[rows];
    for (int i=0; i<rows; i++)
    {
        data[i] = new T[cols];
        for (int j=0; j<cols; j++)
        data[i][j] = 0;
}
}

template<typename T>
Matrix<T>::~Matrix()
{
    for (int i=0; i<rows; i++)
    delete[] data[i];

delete[] data;
data = nullptr;
}

template<typename T>
Matrix<T>::Matrix(const Matrix& other)
{
    rows = other.rows;
    cols = other.cols;
    data = new T*[rows];
    for (int i=0; i<rows; i++)
    {
        data[i] = new T[cols];
        for (int j=0; j<cols; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }
}

template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other)
{
    if (this == &other)
    return *this;

for (int i = 0; i < rows; i++)
delete[] data[i];
delete[] data;

rows = other.rows;
cols = other.cols;
data = new T*[rows];
for (int i = 0; i < rows; i++)
{
    data[i] = new T[cols];
    for (int j = 0; j < cols; j++)
    {
        data[i][j] = other.data[i][j];
    }
}

return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& other) const
{
    if (this->rows != other.rows || this->cols != other.cols)   throw MatrixException("Dimension Mismatch in Matrix Addition!");
    
    Matrix<T> temp(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return temp;
}

template<typename T>
bool Matrix<T>::operator==(const Matrix<T>& other) const
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

template<typename T>
ostream& operator<<(ostream& os, const Matrix<T>& mat)
{
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            os << mat.data[i][j] << '\t';
        }
        os << endl;
    }
    return os;
}

template<typename T>
void Matrix<T>::setElement(int r, int c, T value)
{
    if (r < 0 || r >= rows || c < 0 || c >= cols)   throw MatrixException(r, c);
    
    data[r][c] = value;
}

template<typename T>
T Matrix<T>::getElement(int r, int c) const
{
    if (r < 0 || r >= rows || c < 0 || c >= cols)   throw MatrixException(r, c);

    return data[r][c];
}

template<typename T>
void Matrix<T>::print() const
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