/*
    MVC pattern
        Model
            Model represents an object or JAVA POJO carrying data.
            It can also have logic to update controller if its data changes.

        View
            View represents the visualization of the data that model contains.

        Controller
            Controller acts on both model and view.
            It controls the data flow into model object and updates the view whenever data changes.
            It keeps view and model separate.
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;


class Student {
private:
    string rollNo;
    string name;
public:
    Student(string rollNo, string name): rollNo(rollNo), name(name) {}
    string getRollNo() { return rollNo; }
    void setRollNo(string rollNo) { this->rollNo = rollNo; }
    string getName() { return name; }
    void setName(string name) { this->name = name; }
};


class StudentView {
public:
    void printStudentDetails(string studentName, string studentRollNo) {
        cout << "Studnet: " << endl;
        cout << "Name: " << studentName << endl;
        cout << "Roll No: " << studentRollNo << endl;
    }
};


class StudentController {
private:
    Student model;
    StudentView view;
public:
    StudentController(Student model, StudentView view) {
        this->model = model;
        this->view = view;
    }

    void setStudentName(string name) { model.setName(name); }

    string getStudentName() { return model.getName(); }

    void setStudentRollNo(string rollNo) { model.setRollNo(rollNo); }

    string getStudentRollNo() { return model.getRollNo(); }
};


int main() {
    Student model("0", "kim");
}