#include "Boy.h"
#include "Girl.h"

Boy::Boy(){
	//name = " ";
	//age = 0;
	salary = 0;
}

Boy::Boy(string name, int age, int salary):Single(name,age){
	//this->name = name;
	//this->age = age;
	this->salary = salary;
}
Boy::~Boy(){

}
/*
string Boy::get_name(){
	return name;
}

int Boy::get_age(){
	return age;
}
*/
int Boy::get_salary(){
	return salary;
}

bool Boy::attitude(Girl& girl) {
	int looks = salary * MAXLOOKS;
	if (looks > 100) {
		looks = 100;
	}
	if (girl.get_looks() >=looks) {
		return true;
	}
	else {
		return false;
	}
}
string Boy::print() {
	stringstream ret;
	ret << "����:" << age << " \t����:" << name << "\tн��:" << salary;
	return ret.str();
}

void Boy::inputBoys(vector<Boy>&boys){
	int age;
	string name;
	int salary;
	int n = 1;
	while (1) {
		cout << "�������:" << n << "λС��������:[����0����]";
		cin >> name;
		if (name == "0") {
			break;
		}
		cout << "�������:" << n << "λС��������:";
		cin >> age;
		cout << "�������:" << n << "λС����н��:";
		cin >> salary;
		boys.push_back(Boy(name,age,salary));
		n++;
	}
}

void Boy::inputboy(Boy& boy){
	int age, salary;
	string name;
	cout << "����������:";
	cin >> name;
	cout << "����������:";
	cin >> age;
	cout << "������н��:";
	cin >> salary;
	boy=Boy(name, age, salary);
}

bool Boy::operator>(Boy& boy){
	return this->salary > boy.salary;
}

ostream& operator<<(ostream&os, Boy& boy) {
	os << "�Ա�:��\t����:" << boy.age << " \t����:" << boy.name << "\tн��:" << boy.salary;
	return os;
}
