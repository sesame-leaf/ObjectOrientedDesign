#include <iostream>
#include <vector>
#include <bitset>

using std::cin;
using std::cout;
using std::endl;
using std::oct;
using std::hex;
using std::vector;
using std::bitset;

class Observer;


class Subject {
private:
    vector<Observer*> observers;
    int state;
public:
    Subject(): observers(vector<Observer*>()) {}
    virtual ~Subject() = default;

    int getState() { return state; }

    void setState(int state) {
        this->state = state;
        notifyAllObservers();
    }

    void attach(Observer* observer) { observers.push_back(observer); }

    void notifyAllObservers();
};


class Observer {
protected:
    Subject* subject;
public:
    Observer(Subject* subject) {
        this->subject = subject;
        this->subject->attach(this);
    }
    virtual ~Observer() = default;
    virtual void update() = 0;
};


void Subject::notifyAllObservers() { for (Observer* observer: this->observers) observer->update(); }


class BinaryObserver: public Observer {
public:
    BinaryObserver(Subject* subject): Observer(subject) {}

    void update() override { cout << "Binary String: " << bitset<32>(subject->getState()) << endl; }
};


class OctalObserver: public Observer {
public:
    OctalObserver(Subject* subject): Observer(subject) {}
    
    void update() override { cout << "Octal String: " << oct << subject->getState() << endl; }
};


class HexaObserver: public Observer {
public:
    HexaObserver(Subject* subject): Observer(subject) {}
    
    void update() override { cout << "Hex String: " << hex << subject->getState() << endl; }
};


int main() {
    Subject* subject = new Subject();

    new HexaObserver(subject);
    new OctalObserver(subject);
    new BinaryObserver(subject);

    cout << "First state change: 15" << endl;
    subject->setState(15);

    cout << "Second state change: 10" << endl;
    subject->setState(10);

    return 0;
}