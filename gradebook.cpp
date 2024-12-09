#include "gradebook.h"
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int Gradebook::findStudent(const string& studentID)
{
    int index = 0;
    for (const auto& student : students)
    {
        if(student.getStudentID() == studentID)
        {
            return index;
        }
        index++;
    }
    return -1;
}
int Gradebook::findAssignmentIndex(const string& assignmentName)
{
    int index = 0;
    for (const auto& assignment : assignments)
    {
        if (assignment.getName() == assignmentName)
        {
            return index;
        }
        ++index;
    }
    return -1;
}

void Gradebook::addStudent(const string& firstName, const string& lastName, const string& studentID)
{
    if (findStudent(studentID) == -1)
    {
        students.push_back(Student(firstName, lastName, studentID));
        grades.push_back(vector<int>(assignments.size(), -1));
        
    }
    else
    {
        cout << "Student with that ID already exists!" << endl;
    }
}
void Gradebook::addAssignment(const string& name, int totalPoints)
{
    if (findAssignmentIndex(name) == -1)
    {
        assignments.push_back(Assignment(name, totalPoints));
        for (auto& studentGrades : grades)
        {
            studentGrades.push_back(-1);
        }
    }
    else
    {
        cout << "Assignment with that name already exists!" << endl;
    }
}

void Gradebook::setGrade(const string& studentID, const string& assignmentName, int grade)
{
    int studentIndex = findStudent(studentID);
    if (studentIndex == -1)
    {
        cout << "Student with that ID does not exist!" << endl;
        return;
    }
    int assignmentIndex = findAssignmentIndex(assignmentName);
    if (assignmentIndex == -1)
    {
        cout << "Assignment with that name does not exist!" << endl;
        return;
    }
    grades[studentIndex][assignmentIndex] = grade;
}

void Gradebook::printReport()
{
    cout << setw(10) << "StudentID" << setw(15) << "First Name" << setw(15) << "Last Name";
    for (auto& assignment : assignments)
    {
        cout << setw(15) << assignment.getName();
    }
    cout << endl;

    for (size_t i = 0; i < students.size(); ++i)
    {
         Student& student = students[i];
        cout << setw(10) << student.getStudentID()
             << setw(15) << student.getFirstName()
             << setw(15) << student.getLastName();

        for (size_t j = 0; j < assignments.size(); ++j)
        {
            int grade = grades[i][j];
            if (grade >= 0)
            {
                cout << setw(15) << grade;
            }
            else
            {
                cout << setw(15) << "N/A";
            }
        }
        cout << endl;
    }
}
