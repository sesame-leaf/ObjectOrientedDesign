#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::min_element;
using std::max_element;


int main() {
    vector<int> inputList(10, 0);
    for (int i=0; i<inputList.size(); i++) {
        cin >> inputList[i];
        cout << inputList[i] << "  ";
    }
    cout << endl;

    cout << "min:\t" << *min_element(inputList.begin(), inputList.end()) << endl;
    cout << "max:\t" << *max_element(inputList.begin(), inputList.end()) << endl;
    
    return 0;
}