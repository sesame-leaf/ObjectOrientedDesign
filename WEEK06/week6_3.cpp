#include <iostream>
#include <exception>
#include <string>


// 상속받는 사용자 정의 예외 클래스 작성
class AccountException : public std::exception {
private:
	std::string msg_;
public:
	AccountException(const std::string & msg) : msg_(msg) {}
	// what() 메서드 재정의
	virtual const char* what() const noexcept override {
		return msg_.c_str();
	}
};

void transferMoney(int balance, int amount) {
	std::cout << "Transaction start..." << std::endl;
	try {
		if (balance < amount) {
			throw AccountException("Balance insufficient.");
		}
		std::cout << "Transaction success!" << std::endl;
	}
	catch (...) {
		std::cout << "Error Occur! Run Transaction rollback." << std::endl;
		// [요구사항 2] 포착한 예외를 상위 함수(main)로 다시 던짐(Rethrow)
		throw AccountException("Balance insufficient");
	}
}


int main() {
	try {
		transferMoney(1000, 5000); // 1,000 원 계좌에서 5,000 원 이체 시도
	}
	catch (const std::exception& e) {
		std::cout << "[UI Layer] User notification: " << e.what() << std::endl;
	}
	return 0;
}