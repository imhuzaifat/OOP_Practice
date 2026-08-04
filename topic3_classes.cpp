/*
 * Topic 3: Classes, Objects, & Access Modifiers
 * Problem Set 3: Encapsulated Student Portal
 * 
 * Problem Requirements:
 * 1. Define a 'Student' class with private attributes:
 *    - string name
 *    - int rollNumber
 *    - float gpa
 * 2. Implement public member functions:
 *    - Setters: setName(), setRollNumber(), setGPA()
 *      * Include validation in setGPA() to ensure GPA is between 0.0 and 4.0.
 *    - Getters: getName(), getRollNumber(), getGPA()
 *    - displayInfo(): Displays student details neatly formatted.
 *    - isHonorStudent(): Returns true if GPA >= 3.5, else false.
 * 3. In main():
 *    - Instantiate two Student objects.
 *    - Populate their values using setters (test with valid and invalid GPAs).
 *    - Call displayInfo() and print honor roll status for both students.
 */

#include<iostream>
using namespace std;

