/*
 * Topic 12: Multi-file Project Structuring & Header Files
 * Problem Set 12: Multi-file Matrix Project
 * 
 * Problem Requirements:
 * 1. Separate Matrix into interface (Matrix.h) and implementation (Matrix.cpp).
 * 2. Use include guards (#ifndef / #define / #endif) in Matrix.h.
 * 3. In topic12_multifile.cpp, #include "Matrix.h" and demonstrate class usage.
 */

#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    try {
        Matrix m(2, 2);
        m.setElement(0, 0, 10);
        m.setElement(0, 1, 20);
        m.setElement(1, 0, 30);
        m.setElement(1, 1, 40);

        cout << "Matrix m Output:" << endl;
        cout << m;
    } 
    catch (const MatrixException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}