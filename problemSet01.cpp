//Problem Set 1:
//References & Pointers
//Write a complete C++ program that implements a custom array manipulation function called trimAndFindMax.
//
//Problem Requirements : Write a function with the following signature : int& findMax(int arr[], int size);
//It takes a dynamically allocated integer array and its size.
//It returns a reference to the maximum element in the array.
//In main() :Dynamically allocate an array of integers of size N(prompt the user for size and elements).
//Call findMax to obtain a reference to the maximum element.
//Modify the maximum element directly using the returned reference(e.g., set it to 0 or double its value).
//Print the updated array to demonstrate that the original element inside the array was modified.Properly deallocate memory.

#include<iostream>
using namespace std;

int& findMax(int arr[], int size);
void printIntArray(int arr[], int size);

int main()
{
	int size;
	cout << "Please Enter the Size of Array: ";
	cin >> size;

	int* arrayPtr = new int [size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter " << i + 1 << " Element: ";
		cin >> arrayPtr[i];
	}

	printIntArray(arrayPtr, size);

	findMax(arrayPtr, size) /= 2;

	printIntArray(arrayPtr, size);

	delete[] arrayPtr;
	arrayPtr = nullptr;

	return 0;
}

int& findMax(int arr[], int size)
{
	int maxIndex = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}

	return arr[maxIndex];
}

void printIntArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}