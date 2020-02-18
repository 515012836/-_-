#include "DATABS.h"
#include <fstream>

#define BOY_FILE "boys.txt"
#define GIRL_FILE "girl.txt"

void DATABS::inti(){
	//初始化,单身的信息
	intiBoyfile();
	intiGirlfile();
}

void DATABS::autopair(){
	cout << "***自动配对***" << endl;
	string line(15, '*');
	cout << line << endl;
	//BOY对Girl的匹配
	for (int i = 0; i < boys.size(); i++) {
		for (int k = 0; k < girls.size(); k++) {
			if (boys[i].attitude(girls[k]) && girls[k].attitude(boys[i])) {
				cout << boys[i].print() << endl;
				cout << girls[k].print() <<endl;
				cout<<"可以匹配!" << endl;
				cout << line << endl;
			}
		}
	}
	//Girl对BOY的匹配
	for (int i = 0; i < girls.size(); i++) {
		for (int k = 0; k < boys.size(); k++) {
			if (girls[i].attitude(boys[k]) && boys[k].attitude(girls[i])) {
				cout << girls[i].print() << endl;
				cout << boys[k].print() << endl;
				cout << "可以匹配!" << endl;
				cout << line << endl;
			}
		}
	}
}

void DATABS::Greatpair(){
	cout << "***最佳配对***" << endl;
	string line(15, '*');
	cout << line << endl;
	//BOY对Girl的匹配
	for (int i = 0; i < boys.size(); i++) {
		Girl* Goodgirl = NULL;
		for (int k = 0; k < girls.size(); k++) {
			if (!Goodgirl) {
				Goodgirl = &girls[k];
			}
			else if (girls[k] > * Goodgirl) {
				Goodgirl = &girls[k];
			}
		}
		cout << boys[i] << endl;
		cout << *Goodgirl << endl;
		cout << "可以匹配!" << endl;
		cout << line << endl;
	}
	//Girl对BOY的匹配
	for (int i = 0; i < girls.size(); i++) {
		Boy* Goodboy = NULL;
		for (int k = 0; k < boys.size(); k++) {
			if (Goodboy == NULL) {
				Goodboy = &boys[k];
			}
			else if (boys[k] > *Goodboy) {
				Goodboy = &boys[k];
			}
		}
		cout << girls[i] << endl;
		cout << *Goodboy << endl;
		cout << "可以匹配!" << endl;
		cout << line << endl;
	}
}

void DATABS::print(){
	cout << "***男同志信息***" << endl;
	for (int i = 0; i < boys.size(); i++) {
		cout << boys[i].print() << endl;
	}
	cout << "***女同志信息***" << endl;
	for (int i = 0; i < girls.size(); i++) {
		cout << girls[i].print() << endl;
	}
}

void DATABS::addOne(Boy& boy){
	boys.push_back(boy);//把单个信息保存到数据文本里去
	cout << "***自动配对***" << endl;
	string line(15, '*');
	cout << line << endl;
		for (int k = 0; k < girls.size(); k++) {
			if (boy.attitude(girls[k]) && girls[k].attitude(boy)) {
				cout << boy.print() << endl;
				cout << girls[k].print() << endl;
				cout << "可以匹配!" << endl;
				cout << line << endl;
			}
		}
	}

void DATABS::addOne(Girl& girl){
	girls.push_back(girl);
	cout << "***自动配对***" << endl;
	string line(15, '*');
		for (int k = 0; k < boys.size(); k++) {
			if (girl.attitude(boys[k]) && boys[k].attitude(girl)) {
				cout << girl.print() << endl;
				cout << boys[k].print() << endl;
				cout << "可以匹配!" << endl;
				cout << line << endl;
			}
		}
	}

void DATABS::intiBoyfile(){
	ifstream boyfile;
	boyfile.open(BOY_FILE);
	if (!boyfile) {
		//考虑到最开始时是没有文本的
		cout << "***请输入男用户的信息***" << endl;
		Boy::inputBoys(this->boys);
		saveboy();
		boyfile.close();
		return;
	}
	//文本已经存在
	while (1){
		string line;
		char name[64];
		int age, salary;
		getline(boyfile, line);
		if (boyfile.eof()) {
			break;
		}
		//按格式输出信息,ret表示信息的数量,方便判断
		int ret = sscanf_s(line.c_str(), "年龄:%d 姓名:%s 薪资:%d", &age, name, sizeof(name), &salary);
		if (ret <= 0) {
			cout << "Boy的文件格式匹配失败!" << endl;
			system("pause");
			exit(1);
		}
		boys.push_back(Boy(string(name),age,salary));
	}
	boyfile.close();
}

void DATABS::saveboy(){
	ofstream boyfile;
	boyfile.open(BOY_FILE);
	if (!boyfile) {
		cout << "BOY_FILE文件打开失败" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < boys.size(); i++) {
		boyfile<<boys[i].print() << endl;
	}
	boyfile.close();
}

void DATABS::intiGirlfile(){
	ifstream girlfile;
	girlfile.open(GIRL_FILE);
	if (!girlfile.is_open()) {
		cout << "***输入女用户信息***" << endl;
		Girl::inputGirl(this->girls);
		savegilr();
		girlfile.close();
		return;
	}
	while (1){//判断文本是否读完
		string line;
		char name[64];
		int age, looks;
		getline(girlfile, line);
		if (girlfile.eof()) {
			break;
		}
		//解析字符串line里的信息
		int ret = sscanf_s(line.c_str(), "年龄:%d 姓名:%s 颜值:%d",&age, name, sizeof(name), &looks);
		if (ret <= 0) {
			cout << "Girl文件读取失败!" << endl;
			break;
		}
		//创建一个对象,把读到的信息保存到对象里去;
		girls.push_back(Girl(string(name),age,looks));
	}
	girlfile.close();
}

void DATABS::savegilr(){
	ofstream girlfile;
	girlfile.open(GIRL_FILE);
	if (!girlfile.is_open()) {
		cout << "打开girl.txt文件失败" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < girls.size(); i++) {
		girlfile << girls[i].print() << endl;
	}
	girlfile.close();
}
