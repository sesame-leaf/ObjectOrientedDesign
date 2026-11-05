#include <iostream>
#include <stdexcept>
#include <string>


// 1. 기본 계좌 클래스
class Account {
protected:
	int balance_; // 자식 클래스에서 접근 가능하도록 설정
public:
	// TODO 1: 생성자 구현 (초기 잔액이 0 미만이면 std::invalid_argument 예외 발생)
	Account(int balance) {
		if (balance < 0) throw std::invalid_argument("Initial balance should greater than or equal to 0.");
		balance_ = balance;
	}
	int getBalance() const { return balance_; }
};


// 2. 마이너스 통장 클래스 (Account 상속)
// TODO 2: Account 클래스를 public 상속받도록 선언
class MinusAccount : public Account {
private:
	int limit_; // 마이너스 한도 (예: 10000 이면 -10000 원까지 출금 가능)
public:
	// TODO 3: 생성자 구현 (부모 생성자 명시적 호출 및 limit_ 초기화)
	MinusAccount(int balance, int limit) : Account(balance) {
		limit_ = limit;
	}
	// TODO 4: 출금 함수 구현 (한도 초과 시 std::runtime_error 예외 발생)
	void withdraw(int amount) {
		if (amount > balance_ + limit_) throw std::runtime_error("Can't withdraw out of limitation.");
		balance_ -= amount;
		std::cout << "Withdraw Success!" << std::endl;
	}
};


// 3. 계좌 컨트롤러 클래스
class AccountController {
public:
	void processWithdraw(int initial_balance, int limit, int amount) {
		MinusAccount* acc = nullptr;
		// TODO 5: try-catch 구문을 작성하여 동적 객체 생성 및 출금 로직 실행
		// - 예외가 발생하더라도 동적 할당된 acc 의 메모리가 해제(delete)되어야 함
		// - std::invalid_argument 및 std::runtime_error 예외를 포착하여 에러 메시지 출력
		/* 아래에 try-catch 로직 구현 */
		try {
			acc = new MinusAccount(initial_balance, limit);
			acc->withdraw(amount);
			delete acc; // 메모리 해제
			acc = nullptr;
		}
		catch (const std::invalid_argument& e) {
			// 생성자 호출 중 에러가 발생했기 때문에 따로 메모리를 해제하지 않아도 됨.
			std::cout << "[invalid argument exception occur]: " << e.what() << std::endl;
		}
		catch (const std::runtime_error& e) {
			std::cout << "[runtime error exception occur]: " << e.what() << std::endl;
			if (acc) {
				delete acc;
				acc = nullptr;
			}
		}
	}
};


int main() {
	AccountController controller;
	const int limit = 50000;
	std::cout << "Transaction 1" << std::endl;
	controller.processWithdraw(10000, limit, 30000); // 10,000 원에서 30,000 원 출금(잔액: -20, 000 원)
	std::cout << "\nTransaction 2" << std::endl;
	controller.processWithdraw(10000, limit, 70000); // 10,000 원에서 70,000 원 출금 시도(한도 - 50, 000 원 초과)
	std::cout << "\nTransaction 3" << std::endl;
	controller.processWithdraw(-5000, limit, 10000); // 초기 잔액 음수 설정

	return 0;
}