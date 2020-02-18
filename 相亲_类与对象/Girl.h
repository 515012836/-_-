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
	static void inputGirl(vector<Girl>&girls);//������Girl����Ϣ
	static void inputGirls(Girl& girl);//���뵥����Ϣ
	bool operator>(Girl& girl);//�ȽϺ���
	friend ostream& operator<<(ostream& os, Girl& girl);//��Girl.cpp�ļ���ʵ�ֵ���Ԫ��ӡ����
private:
	//string name;
	//int age;
	int looks;
};

