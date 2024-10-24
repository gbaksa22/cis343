#include "Student.h"
#include <iostream>
void Student::printStudent() {
    std::cout << name << "has a GPA of" << gpa << " and Gnumber" << gNumber << std::endl;
}

std::string Student::getStudent() {
    return name;
}

void setStudent(std::string name) {
    this->name = name;
}

int main(int argc, char** argv) {
    Student a;
    int c;
    a.setStudent("Ira");
    

}