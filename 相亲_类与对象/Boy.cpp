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
	ret << "年龄:" << age << " \t姓名:" << name << "\t薪资:" << salary;
	return ret.str();
}

void Boy::inputBoys(vector<Boy>&boys){
	int age;
	string name;
	int salary;
	int n = 1;
	while (1) {
		cout << "请输入第:" << n << "位小哥哥的姓名:[输入0结束]";
		cin >> name;
		if (name == "0") {
			break;
		}
		cout << "请输入第:" << n << "位小哥哥的年龄:";
		cin >> age;
		cout << "请输入第:" << n << "位小哥哥的薪资:";
		cin >> salary;
		boys.push_back(Boy(name,age,salary));
		n++;
	}
}

void Boy::inputboy(Boy& boy){
	int age, salary;
	string name;
	cout << "请输入姓名:";
	cin >> name;
	cout << "请输入年龄:";
	cin >> age;
	cout << "请输入薪资:";
	cin >> salary;
	boy=Boy(name, age, salary);
}

bool Boy::operator>(Boy& boy){
	return this->salary > boy.salary;
}

ostream& operator<<(ostream&os, Boy& boy) {
	os << "性别:男\t年龄:" << boy.age << " \t姓名:" << boy.name << "\t薪资:" << boy.salary;
	return os;
}
