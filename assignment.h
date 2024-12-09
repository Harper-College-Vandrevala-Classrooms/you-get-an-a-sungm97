#pragma once

#include <string>

using namespace std;

class Assignment
{
          
    private:
        string name;
        int totalPoints;
    public:
        Assignment(const string& name, int totalPointsPossible) : name(name)
        {
            this->totalPoints = totalPoints;
        }
        string getName() const
        {
            return name;
        }
        int getPoints() const
        {
            return totalPoints;
        }
};