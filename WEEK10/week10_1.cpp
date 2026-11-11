#include <iostream>


class BaseClass {
public:
    virtual ~BaseClass() = default;
};


class DerivedClass : public BaseClass {
public:
    void specificFunction() { std::cout << "Everything is OKAY\n"; }
};


int main() {
    BaseClass* base = new DerivedClass();
    DerivedClass* derived = static_cast<DerivedClass*>(base);
    if (DerivedClass* d = dynamic_cast<DerivedClass*>(derived))
        derived->specificFunction();
    delete base;

    return 0;
}