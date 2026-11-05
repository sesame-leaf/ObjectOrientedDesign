#include <iostream>
#include <string>


class Person {
public:
	Person(const std::string& name) : name_(name) {}

	void printName() const {
		std::cout << "Name: " << name_ << std::endl;
	}
protected:
	std::string name_;
};


// Person 을 상속받는 Student 클래스
class Student : public Person {
public:
	// (문제 1) Student 생성자
	Student(const std::string& name, int student_id) : Person(name) {
		student_id_ = student_id;
	}
	void printStudentInfo() const {
		// (문제 2) 부모의 name_ 멤버에 직접 접근하여 출력
		std::cout << "Name: " << name_ << ", ID: " << student_id_ << std::endl;
	}
private:
	int student_id_;
};


int main() {
	Student s("ChulSu Kim", 20260001);
	s.printStudentInfo();
	return 0;
}
