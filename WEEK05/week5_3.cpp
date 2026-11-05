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
	// operator+ 구현
	Animal operator+(const Animal& other) {
		return Animal(this->name + other.name);
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