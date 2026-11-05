/*
* Manager, Intern, Janitor가 Employee를 각각 상속받고 있다.
*/


#include <iostream>
#include <string>


class Employee {
protected:
	std::string name;
	int age;
public:
	Employee(std::string name, int age) : name(name), age(age) {}
	virtual ~Employee() = default;
	void showInfo() {
		std::cout << "Name:" << name << ", Age: " << age << std::endl;
	}
};


class Manager : public Employee {
	int managerBonus;
public:
	Manager(int managerBonus, std::string name, int age): managerBonus(managerBonus), Employee(name, age) {}
	void showInfo() {
		std::cout << "Manager Name:" << name << ", Age: " << age << ", managerBonus:" << managerBonus << std::endl;
	}
};


class Intern : public Employee {
	std::string majorName;
public:
	Intern(std::string major, std::string name, int age)
		: majorName(major), Employee(name, age) {
	}
	void showInfo() {
		std::cout << "Intern Name:" << name << ", Age: " << age << ",Major:" << majorName << std::endl;
	}
};


class Janitor : public Employee {
	int salary;
public:
	Janitor(int salary, std::string name, int age): salary(salary), Employee(name, age) {}
	void showInfo() {
		std::cout << "Janitor Name:" << name << ", Age: " << age << ", Salary:" << salary << std::endl;
	}
};


int main() {
	std::cout << "==================== Original method ====================" << std::endl;
	Manager** managerlist = new Manager * [2];
	Intern** internlist = new Intern * [2];
	Janitor** janitorlist = new Janitor * [2];
	managerlist[0] = new Manager(200, "James", 33);
	managerlist[1] = new Manager(150, "Chulsoo", 50);
	internlist[0] = new Intern("security", "Minsu", 24);
	internlist[1] = new Intern("HCI", "Yong", 19);
	janitorlist[0] = new Janitor(100, "Black", 90);
	janitorlist[1] = new Janitor(200, "White", 100);
	managerlist[0]->showInfo();
	managerlist[1]->showInfo();
	internlist[0]->showInfo();
	internlist[1]->showInfo();
	janitorlist[0]->showInfo();
	janitorlist[1]->showInfo();

	std::cout << std::endl << "==================== New method ====================" << std::endl;

	Employee** employeelist = new Employee * [6];
	employeelist[0] = managerlist[0];
	employeelist[1] = managerlist[1];
	employeelist[2] = internlist[0];
	employeelist[3] = internlist[1];
	employeelist[4] = janitorlist[0];
	employeelist[5] = janitorlist[1];

	for (int i = 0; i < 6; i++) {
		if (i == 0 || i == 1)
			dynamic_cast<Manager*>(employeelist[i])->showInfo();
		else if (i == 2 || i == 3)
			dynamic_cast<Intern*>(employeelist[i])->showInfo();
		else
			dynamic_cast<Janitor*>(employeelist[i])->showInfo();
	}

	getchar();
	return 0;
}
