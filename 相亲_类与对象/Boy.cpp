#include "Boy.h"
#include "Girl.h"

Boy::Boy(){
	name = " ";
	age = 0;
	salary = 0;
}

Boy::Boy(string name, int age, int salary){
	this->name = name;
	this->age = age;
	this->salary = salary;
}
Boy::~Boy(){

}
string Boy::get_name(){
	return name;
}

int Boy::get_age(){
	return age;
}

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
	ret << name << ",���䣺" << age << ",н�ʣ�" << salary;
	return ret.str();
}

void Boy::inputBoys(vector<Boy>&boys){
	int age;
	string name;
	int salary;
	int n = 1;
	while (1) {
		cout << "�������:" << n << "λС��������[����0����]";
		cin >> age;
		if (age == 0) {
			break;
		}
		cout << "�������:" << n << "λС��������:";
		cin >> name;
		cout << "�������:" << n << "λС����н��:";
		cin >> salary;
		boys.push_back(Boy(name,age,salary));
		n++;
	}
}
