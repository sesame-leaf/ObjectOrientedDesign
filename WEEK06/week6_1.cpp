#include <iostream>
#include <stdexcept>
#include <string>


void printMessage(const std::string& msg) noexcept {
	std::cout << "[LOG] " << msg << std::endl;
}


double calculateSquareRoot(double x) {
	if (x < 0) throw std::invalid_argument("Can't calculate negative integer's square root.");
	return x;
}

int getElement(int arr[], int size, int idx) {
	if (idx < 0 || idx >= size) throw std::out_of_range("Array index out of range.");
	return arr[idx];
}


int main() {
	try {
		int arr[5] = { 0, };
		printMessage("Start Program");
		getElement(arr, 5, 6);
	}
	catch (const std::exception& e) {
		std::cout << "Exception 1 raised: " << e.what() << std::endl;
		try {
			calculateSquareRoot(-5.0);
		}
		catch (const std::exception& e) {
			std::cout << "Exception 2 raised: " << e.what() << std::endl;
		}
	}

	system("pause");
	return 0;
}