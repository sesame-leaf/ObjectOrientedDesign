#include <iostream>

class Set {
	int num;
	char word;

public:
	void set_value(int i) {
		this->num = i;
	}

	void set_value(char c) {
		this->word = c;
	}

	void show() {
		std::cout << "num = " << this->num << ", word = " << this->word << std::endl;
	}
};

int main() {
	Set s;
	s.set_value(3);
	s.set_value('c');
	s.show();
}