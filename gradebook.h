#pragma once

#include "student.h"
#include "assignment.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Gradebook
{
    private:
        vector<Student> students;
        vector<Assignment> assignments;
        vector<vector<int> > grades;
    public:
        int findStudent(const string& studentID);
        void addStudent(const string& firstName, const string& lastName, const string& studentID);
        void addAssignment(const string& name, int totalPoints);
        int findAssignmentIndex(const string& assignmentName); 
        void setGrade(const string& studentID, const string& assignmentName, int grade);
        void printReport();
};