#pragma once

#include <string>

using namespace std;

class Student
{
    private:
        string firstName;
        string lastName;
        string studentID;

    public:
        Student(const string& firstName, const string& lastName, const string& studentID)
        : firstName(firstName), lastName(lastName), studentID(studentID) {}
        //Student(string& firstName, string& lastName, string& studentID);
        string getFirstName() const
        {
            return firstName;
        }
        string getLastName() const
        {
            return lastName;
        }
        string getStudentID() const
        {
            return studentID;
        }
};