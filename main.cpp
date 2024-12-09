#include "gradebook.h"

int main()
{
    Gradebook book;
    book.addStudent("Sam", "Cho", "0001");
    book.addStudent("Jane", "Han", "0002");
    book.addStudent("Jane", "Han", "0002");

    book.addAssignment("Portfolio 1", 100);
    book.addAssignment("Portfolio 2", 100);

    book.setGrade("0001", "Portfolio 1", 100);
    book.setGrade("0002", "Portfolio 1", 99);

    book.setGrade("0001", "Portfolio 2", 100);
    book.printReport();
    return 0;
}
