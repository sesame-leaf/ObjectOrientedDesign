#include <iostream>
#include <cassert>


class Student {
public:
    void speak() { std::cout << "i'm student" << std::endl; }
    virtual ~Student() = default;
};


class Employee {
public:
    void speak() { std::cout << "i'm employee" << std::endl; }
    virtual ~Employee() = default;
};


class TA: public Student, public Employee {
public:
    void speak() { std::cout << "i'm TA" << std::endl; }
};


class Undergraduate: public Student {
public:
    void speak() { std::cout << "i'm undergraduate" << std::endl; }
};


int main() {
    Employee* ta_AsEmployee = new TA();
    Student* ta_AsStudent = dynamic_cast<Student*>(ta_AsEmployee);
    assert(ta_AsStudent != nullptr);
    std::cout << "problem 1 pass" << std::endl;

    Employee* undergraduate_AsEmployee = (Employee*) new Undergraduate();
    TA* undergraduate_AsTA = dynamic_cast<TA*>(undergraduate_AsEmployee);
    assert(undergraduate_AsTA == nullptr);
    std::cout << "problem 2 pass" << std::endl;

    delete ta_AsEmployee;
    delete undergraduate_AsEmployee;
    
    return 0;
}