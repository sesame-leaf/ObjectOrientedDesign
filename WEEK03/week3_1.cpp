// 실습 1

/*
* x = 55
* x 값이 increment() 함수 안에서만 변경되었다. (지역변수를 변경했다.)
*/

#include <iostream>

void increment(int x) {
	++x;
}

int main() {
	int x = 55;

	std::cout << " Before increment: " << x << std::endl;
	increment(x);
	std::cout << " After increment: " << x << std::endl;

	system("pause");
	return 0;
}