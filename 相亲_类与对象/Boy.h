#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Girl;
#define MAX_SALARY 100
class Boy{
public:
	Boy();
	Boy(string, int, int);
	~Boy();
	string get_name();
	int get_age();
	int get_salary();
	bool attitude(Girl&girl);
	string print();//打印信息
	static void inputBoys(vector<Boy>&boys);//输入多个Boy的信息
private:
	string name;
	int age;
	int salary;
};

