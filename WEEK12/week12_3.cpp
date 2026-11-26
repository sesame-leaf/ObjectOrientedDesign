#include <iostream>


template<typename T>
T min(T x, T y) {
    return x < y ? x : y;
}


int main() {
    int x = 3;
    int y = 2;
    double d = 2.1;
    double e = 3.3;
    // int와 double을 동시에 받는 template이 없기 때문임. 따라서 자동으로 int를 double로 casting할 수 있도록 명시해줘야함
    std::cout << "min(x,y): " << min(x, y) << ", min(d,e): " << min(d, e) << ", min(d, x): " << min<double>(d, x) << std::endl;
    return 0;
}