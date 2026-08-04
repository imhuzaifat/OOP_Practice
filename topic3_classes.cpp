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

class Student
{
private:
    string name;
    int rollNumber;
    float gpa;
public:
    // Setter Methods / Functions
    void setName(string);
    void setRollNumber(int);
    void setGPA(float GPA = 0.0);
    // Getter Methods / Functions
    string getName() const;
    int getRollNumber() const;
    float getGPA() const;
    void displayInfo() const;
    bool isHonorStudent() const;
};

int main()
{
    // Instantiating Two Different Students
    Student stu1, stu2;

    //Populating First Student with All Valid Values
    stu1.setName("Huzaifa");
    stu1.setRollNumber(15);
    stu1.setGPA(3.8);

    // Populating Second Student with Invalid GPA
    stu2.setName("Hamza");
    stu2.setRollNumber(25);
    stu2.setGPA(6.7);

    // Displaying Details of Student 1
    stu1.displayInfo();
    if(stu1.isHonorStudent())
        cout << "Congratulations! Keep on the Hard Work." << endl;

    // Displaying Details of Student 2
    stu2.displayInfo();
    if(stu2.isHonorStudent())
        cout << "Congratulations! Keep on the Hard Work." << endl;

    return 0;
}

void Student::setName(string name)
{
    this->name = name;
}

void Student::setRollNumber(int rollNumber)
{
    this->rollNumber = rollNumber;
}

void Student::setGPA(float gpa)
{
    if(gpa >= 0.0 && gpa <= 4.0)
        this->gpa = gpa;
    else
    {
        this->gpa = 0.0;
        cout << "Invalid GPA Entered!" << endl;
    }
}

string Student::getName() const
{
    return name;
}

int Student::getRollNumber() const
{
    return rollNumber;
}

float Student::getGPA() const
{
    return gpa;
}

void Student::displayInfo() const
{
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << rollNumber << endl;
    cout << "GPA: " << gpa << endl;
}

bool Student::isHonorStudent() const
{
    if(gpa >= 3.5)
        return true;
    return false;
}