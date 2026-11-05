/*
* 3.1 생성자가 호출되는 순서:
* Derived -> Base1 -> Base2
* 
* 3.2 상속 순서가 바뀌었을 경우 호출되는 순서:
* Derived -> Base2 -> Base1
*/

#include <vector>
#include <string>
#include <iostream>


class Base1 {
public:
	Base1(int n) : vector_(n, 3) {
		std::cout << "Base1 constructor called." << std::endl;
	}
private:
	std::vector<char> vector_;
};


class Base2 {
public:
	Base2(int n) : vector_(n, 3) {
		std::cout << "Base2 constructor called." << std::endl;
	}
private:
	std::vector<char> vector_;
};


class Derived : public Base1, Base2 {
public:
	Derived(const std::string& str) : Base2(1024), Base1(512) {
		i = 0;
	}
private:
	std::string str_;
	int i = 0;
};


int main() {
	Derived drv("1");
	return 0;
}
