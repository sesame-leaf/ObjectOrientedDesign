#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::sort;


class Rect {
private:
    int w, h;
public:
    Rect(): w(0), h(0) {}
    Rect(int w, int h): w(w), h(h) {}
    int area() { return w * h; }
    void print() { cout << "(" << w << ',' << h << ',' << area() << ')' << endl; }
};


int main() {
    int rectNum;
    cout << "Count: ";
    cin >> rectNum;

    vector<Rect> rectList(rectNum);
    for (int i=0; i<rectList.size(); i++) {
        int w, h;
        cout << "Width: ";
        cin >> w;
        cout << "Height: ";
        cin >> h;
        rectList[i] = Rect(w, h);
    }

    sort(rectList.begin(), rectList.end(), [](Rect& a, Rect& b) { return a.area() < b.area(); });

    for (int i=0; i<rectList.size(); i++) rectList[i].print();

    return 0;
}