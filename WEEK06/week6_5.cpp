#include <iostream>
#include <stdexcept>


class Calculator {
public:
	Calculator() : result_(0) {}

	double add(double a, double b) {
		result_ = a + b;
		return result_;
	}

	double subtract(double a, double b) {
		result_ = a - b;
		return result_;
	}

	double multiply(double a, double b) {
		result_ = a * b;
		return result_;
	}

	double divide(double a, double b) {
		if (b == 0) throw std::invalid_argument("Can't divide by 0.");
		result_ = a / b;
		return result_;
	}
protected:
	double result_;
};


class EngineeringCalculator : public Calculator {
public:
	double percentage(double total, double percent) {
		if (percent < 0) throw std::out_of_range("percentage should greater than or equal to 0.");
		result_ = total * (percent / 100.0);
		return result_;
	}
};


class CalculatorController {
public:
	double runDivideProcess(double a, double b) {
		Calculator* calc = new Calculator();
		try {
			double result = calc->divide(a, b);
			delete calc;
			calc = nullptr;
			
			std::cout << "[division result]: " << result << std::endl;
			std::cout << "[CalculatorController] dynamic object memory free success." << std::endl;

			return result;
		}
		catch (const std::invalid_argument& e) {
			std::cout << "[invalid argument error occur] " << e.what() << std::endl;
			if (calc) {
				delete calc;
				calc = nullptr;
			}
		}
	}

	double runPercentProcess(double total, double percent) {
		EngineeringCalculator* calc = new EngineeringCalculator();
		try {
			double result = calc->percentage(total, percent);
			delete calc;
			calc = nullptr;

			std::cout << "[percentage result]: " << result << std::endl;
			std::cout << "[CalculatorController] dynamic object memory free success." << std::endl;

			return result;
		}
		catch (const std::out_of_range& e) {
			std::cout << "[range exception error occur] " << e.what() << std::endl;
			if (calc) {
				delete calc;
				calc = nullptr;
			}
		}
	}
};


int main() {
	CalculatorController controller;
	std::cout << "case1" << std::endl;
	controller.runDivideProcess(10, 2);
	controller.runPercentProcess(200, 15);
	std::cout << "\ncase2" << std::endl;
	controller.runDivideProcess(5, 0);
	std::cout << "\ncase3" << std::endl;
	controller.runPercentProcess(100, -10);
	return 0;
}