/*
 * Topic 13: Standard Template Library (STL) Fundamentals
 * Problem Set 13: STL Matrix Flattening & Analysis
 * 
 * Problem Requirements:
 * 1. Utilize std::vector<std::vector<int>> to represent a 2D matrix structure.
 * 2. Flatten 2D grid data into a 1D std::vector<int>.
 * 3. Store element indices as std::pair<int, int> objects.
 * 4. Sort the flattened vector using std::sort from <algorithm>.
 * 5. Display grid, flattened vector, and indexed pairs using iterators / range-based loops.
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    // Instantiate a 2D matrix structure using nested std::vectors: vector<vector<int>> grid.
    vector<vector<int>> grid;

    // Populate a $3 \times 3$ grid with non-sorted integers (e.g., 45, 12, 89, 3, 67, 23, 91, 11, 34).
    grid = {{45, 12, 89}, {3, 67, 23}, {91, 11, 34}};

    // Flatten the Matrix: Convert the 2D grid into a single 1D std::vector<int> flattened.
    vector<int> flattened;
    for (int i=0; i<3; ++i)
        for (int j=0; j<3; ++j)
            flattened.push_back(grid[i][j]);

    // Pair Coordinates: Create a std::vector<pair<int, int>> coordinates storing (row, col) pairs for each element.
    vector<pair<int, int>> coordinates;
    for (int i=0; i<3; ++i)
        for (int j=0; j<3; ++j)
            coordinates.push_back({i, j});
    
    // Sort the Flattened Array: Use std::sort(flattened.begin(), flattened.end()) to sort the 1D vector in ascending order.
    sort(flattened.begin(), flattened.end());

    // Display the original 3 x 3 grid using range-based for loops.
    cout << "Original 3x3 Grid:" << endl;
    for (const auto& row : grid)
    {
        for (const auto& col : row)
            cout << col << '\t';
        cout << endl;
    }
    
    // Display the sorted 1D vector.
    cout << "Sorted Flattened Vector:" << endl;
    vector<int>::iterator it;
    for (it = flattened.begin(); it != flattened.end(); ++it)
        cout << *it << " ";

    cout << endl;

    // Display the element at coordinate (1, 1) using vector element access.
    cout << "Element at Coordinates(" << coordinates[4].first << ", " << coordinates[4].second << ") is: ";
    cout << grid[coordinates[4].first][coordinates[4].second] << endl;

    return 0;
}