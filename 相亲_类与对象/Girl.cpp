#include "Girl.h"
#include "Boy.h"

Girl::Girl(){
	name = " ";
	age = 0;
	looks = 0;
}

Girl::Girl(string name, int age, int looks){
	this->name = name;
	this->age = age;
	this->looks = looks;
}
Girl::~Girl(){

}
string Girl::get_name(){
	return name;
}

int Girl::get_age(){
	return age;
}

int Girl::get_looks(){
	return looks;
}

bool Girl::attitude(Boy& boy) {
	if (boy.get_salary() >=looks*MAX_SALARY) {
		return true;
	}
	else {
		return false;
	}
}

string Girl::print(){
	stringstream ret;
	ret << name << ",���䣺" << age << ",��ֵ��" << looks;
	return ret.str();
}

void Girl::inputGirl(vector<Girl>&girls){
	int age;
	string name;
	int looks;
	int n = 1;
	while (1) {
		cout << "�������:" << n << "λС��������[����0����]";
		cin >> age;
		if (age == 0) {
			break;
		}
		cout << "�������:" << n << "λС��������:";
		cin >> name;
		cout << "�������:" << n << "λС������ֵ:";
		cin >> looks;
		girls.push_back(Girl(name, age, looks));
		n++;
	}
}
