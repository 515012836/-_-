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
	string print();//��ӡ��Ϣ
	static void inputBoys(vector<Boy>&boys);//������Boy����Ϣ
	static void inputboy(Boy& boy);//���뵥��boy����Ϣ
	bool operator>(Boy& boy);//�ȽϺ���
	friend ostream& operator<<(ostream& os, Boy& boy);//ֱ�Ӵ�ӡ����
private:
	//string name;
	//int age;
	int salary;
};

