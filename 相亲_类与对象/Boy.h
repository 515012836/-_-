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
	string print();//��ӡ��Ϣ
	static void inputBoys(vector<Boy>&boys);//������Boy����Ϣ
private:
	string name;
	int age;
	int salary;
};

