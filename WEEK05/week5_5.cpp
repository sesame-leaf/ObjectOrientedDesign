#include <iostream>

using namespace std;


class Timer {
private:
	int min;
	int sec;

public:
	// TODO 1: 기본 생성자 및 매개변수 생성자 구현
	Timer(int min, int sec) : min(min), sec(sec) {}

	// TODO 2: Getter 메서드 (getMin, getSec) 구현
	int getMin() { return min; }
	int getSec() { return sec; }

	// TODO 3-(1~3): 연산자 오버로딩 (+, +=, 전위 ++) 구현
	Timer operator+(const Timer& other);
	Timer& operator+=(const Timer& other);
	Timer& operator++();

	// TODO 4: printTime() 메서드 구현
	void printTime();
};

Timer Timer::operator+(const Timer& other) {
	int newMin = this->min + other.min;
	int newSec = this->sec + other.sec;

	if (newSec >= 60) {
		newMin += newSec / 60;
		newSec = newSec % 60;
	}

	return Timer(newMin, newSec);
}

Timer& Timer::operator+=(const Timer& other) {
	min += other.min;
	sec += other.sec;

	if (sec >= 60) {
		min += min / 60;
		sec = sec % 60;
	}

	return *this;
}

Timer& Timer::operator++() {
	min++;
	sec++;

	if (sec >= 60) {
		min += min / 60;
		sec = sec % 60;
	}

	return *this;
}

void Timer::printTime() {
	std::cout << min << "min " << sec << "sec" << std::endl;
}


// 아래 main 함수는 수정 금지
int main() {
	Timer t1(1, 45);
	Timer t2(0, 30);
	cout << "Initial Timer" << endl;
	t1.printTime();
	t2.printTime();
	cout << "\nTotal Timer" << endl;
	Timer total = t1 + t2;
	total.printTime();
	cout << "\nChaining" << endl;
	(++t1) += t2;
	t1.printTime();
	return 0;
}