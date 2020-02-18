#include "Girl.h"
#include "Boy.h"

Girl::Girl(){
	//name = " ";
	//age = 0;
	looks = 0;
}

Girl::Girl(string name, int age, int looks):Single(name,age){
	//this->name = name;
	//this->age = age;
	this->looks = looks;
}
Girl::~Girl(){

}
/*
string Girl::get_name(){
	return name;
}

int Girl::get_age(){
	return age;
}
*/
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
	ret <<"年龄:"<< age << " \t姓名:" << name << "\t颜值:" << looks;
	return ret.str();
}

void Girl::inputGirl(vector<Girl>&girls){
	int age;
	string name;
	int looks;
	int n = 1;
	while (1) {
		cout << "请输入第:" << n << "位小姐姐的姓名[输入0结束]:";
		cin >> name;
		if (name == "0") {
			break;
		}
		cout << "请输入第:" << n << "位小姐姐的年龄:";
		cin >> age;
		cout << "请输入第:" << n << "位小姐姐的颜值:";
		cin >> looks;
		girls.push_back(Girl(name, age, looks));
		n++;
	}
}

void Girl::inputGirls(Girl& girl){
	int age, looks;
	string name;
	cout << "请输入姓名:";
	cin >> name;
	cout << "请输入年龄:";
	cin >> age;
	cout << "请输入颜值:";
	cin >> looks;
	girl = Girl(name, age, looks);
}

bool Girl::operator>(Girl& girl){
	return this->looks > girl.looks;
}

ostream& operator<<(ostream& os, Girl& girl) {
	os << "性别:女\t年龄:" << girl.age << " \t姓名:" << girl.name << "\t颜值:" << girl.looks;
	return os;
}
