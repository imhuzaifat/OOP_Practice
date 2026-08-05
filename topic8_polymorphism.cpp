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

int main()
{
	
	return 0;
}