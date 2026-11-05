/*
* 새 객체를 반환 하느냐, 자기 자신의 name을 바꿔서 반환하느냐의 차이.
*/

#include <iostream>
#include <cstring>


class Animal {
private:
	std::string name;
public:
	Animal() {};
	Animal(std::string name) : name(name) {};
	void showName() {
		std::cout << "Name is " << name << std::endl;
	}
	Animal& operator+(const Animal& a)
	{
		name += a.name;
		return *this;
	}
};


int main() {
	Animal cat("Nabi");
	cat.showName();
	Animal dog("Jindo");
	dog.showName();
	Animal catDog = dog + cat;
	catDog.showName();
	dog.showName();
	return 0;
}