#pragma once
#include <vector>
#include "Single.h"

using namespace std;
class Girl;
#define MAX_SALARY 100

class Boy:public Single{
public:
	Boy();
	Boy(string, int, int);
	~Boy();
	//string get_name();
	//int get_age();
	int get_salary();
	bool attitude(Girl&girl);
	string print();//打印信息
	static void inputBoys(vector<Boy>&boys);//输入多个Boy的信息
	static void inputboy(Boy& boy);//输入单个boy的信息
	bool operator>(Boy& boy);//比较函数
	friend ostream& operator<<(ostream& os, Boy& boy);//直接打印函数
private:
	//string name;
	//int age;
	int salary;
};

