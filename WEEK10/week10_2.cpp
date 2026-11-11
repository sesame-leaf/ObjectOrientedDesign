#include <iostream>
#include <cassert>	
#include <typeinfo>


class CEO { public: virtual ~CEO() {} };
class CPO { public: virtual ~CPO() {} };	
class Manager: public CEO, public CPO {};	
class Staff: public	Manager {};


int main() {
    CPO* cpo = new Staff();
    Staff* staff = dynamic_cast<Staff*>(cpo);
    
    // cpo는 CPO* 타입이므로 Staff* 타입과 정확히 일치하지 않음.
    assert(typeid(*cpo) == typeid(Staff));
    std::cout << "Assertion Pass!\n";
    delete cpo;

    return 0;
}