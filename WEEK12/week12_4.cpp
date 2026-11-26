#include <iostream>

using namespace std;


/*
    아마 template이라고 다 같은 함수가 아니고 
    T의 종류마다 함수가 만들어지기 때문에 
    static int count도 타입마다 생기는듯함.
*/
template <typename T>
void fun(const T& x) {
    static int count = 0;
    cout << "x = " << x << " count = " << count << endl;
    ++count;
    return;
}


int main() {
    fun<int>(1);
    cout << endl;
    fun<int>(1);
    cout << endl;
    fun<double>(1.1);
    cout << endl;

    return 0;
}