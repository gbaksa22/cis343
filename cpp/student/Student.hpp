#ifndef __BLAH__
#define __BLAH__

class Student
    public:
        void printStudent();
        std::string getStudent();
        // :: = namespace (where the function lives)
        
    private:
        std::string name;
        float gpa;
        int gNumber;