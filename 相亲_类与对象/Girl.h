#pragma once
#include <sstream>
#include <vector>
#include "Single.h"

using namespace std;
#define MAXLOOKS 0.006

class Boy;
class Girl:public Single{
public:
	Girl();
	Girl(string, int, int);
	~Girl();
	//string get_name();
	//int get_age();
	int get_looks();
	bool attitude(Boy& boy);
	string print();
	static void inputGirl(vector<Girl>&girls);//输入多个Girl的信息
	static void inputGirls(Girl& girl);//输入单个信息
	bool operator>(Girl& girl);//比较函数
	friend ostream& operator<<(ostream& os, Girl& girl);//在Girl.cpp文件下实现的友元打印函数
private:
	//string name;
	//int age;
	int looks;
};

