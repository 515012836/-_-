#pragma once
#include <string>
#include <sstream>
#include <vector>

using namespace std;
#define MAXLOOKS 0.006
class Boy;
class Girl{
public:
	Girl();
	Girl(string, int, int);
	~Girl();
	string get_name();
	int get_age();
	int get_looks();
	bool attitude(Boy& boy);
	string print();
	static void inputGirl(vector<Girl>&girls);//输入多个Girl的信息
private:
	string name;
	int age;
	int looks;
};

