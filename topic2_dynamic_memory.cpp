/*
 * Topic 2: Dynamic Memory Management
 * Problem Set 2: 2D Dynamic Array Transposition
 * 
 * Requirements:
 * 1. Implement helper functions:
 *    - int** createMatrix(int rows, int cols)
 *    - void freeMatrix(int** matrix, int rows)
 * 2. Implement transposition function:
 *    - int** transposeMatrix(int** matrix, int rows, int cols)
 * 3. In main():
 *    - Prompt for dimensions R and C.
 *    - Allocate, input, transpose, and print matrices.
 *    - Properly deallocate memory to avoid memory leaks.
 */

#include <iostream>
using namespace std;

int** createMatrix(int rows, int cols);
void freeMatrix(int** matrix, int rows);
int** transposeMatrix(int** matrix, int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);

int main()
{
    int rows, cols;
    cout << "Please Enter the Number of Rows: ";
    cin >> rows;
    cout << "Please Enter the Number of Columns: ";
    cin >> cols;
 
    // Create and input the original matrix
    int** matrix = createMatrix(rows, cols);

    // Print original matrix
    cout << "Original Matrix:" << endl;
    printMatrix(matrix, rows, cols);

    // Transpose the matrix
    int** transposedMatrix = transposeMatrix(matrix, rows, cols);

    // Display the transposed matrix
    cout << "Transposed Matrix:" << endl;
    printMatrix(transposedMatrix, cols, rows);

    // Free allocated memory
    freeMatrix(matrix, rows);
    freeMatrix(transposedMatrix, cols);

    return 0;
}

int** createMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];
    for (int i=0; i<rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j=0; j<cols; j++)
        {
            cout << "Please Enter the Element (" << i+1 << "," << j+1 << "): ";
            cin >> matrix[i][j];
        }
    }
    return matrix;
}

int** transposeMatrix(int** matrix, int rows, int cols)
{
    int** transposedMatrix = new int*[cols];
    for (int i=0; i<cols; i++)
    {
        transposedMatrix[i] = new int[rows];
        for (int j=0; j<rows; j++)
        {
            transposedMatrix[i][j] = matrix[j][i];
        }
    }
    return transposedMatrix;
}

void freeMatrix(int** matrix, int rows)
{
    for (int i=0; i<rows; i++)
        delete[] matrix[i];
    
    delete[] matrix;
}

void printMatrix(int** matrix, int rows, int cols)
{
    for (int i=0; i<rows; i++)
    {
        for (int j=0; j<cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}