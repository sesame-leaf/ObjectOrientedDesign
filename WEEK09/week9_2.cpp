class Base {
public:
	void func_1() {};
protected:
	void func_2() {};
private:
	int x_;
};


/*
* Base 클래스를 protected로 상속받았기 때문에
* main에서 Base의 메서드에 접근할 수 없다.
*/
class Derived : public Base {
public:
	void func_3() {
		func_1();
		func_2();
	}
};


int main() {
	Derived d;
	d.func_3();
	d.func_1();
}