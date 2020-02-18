#pragma once
#include <iostream>
#include <string>

using namespace std;

class Single{
public:
	Single() {
		name = " ";
		age = 0;
	}
	Single(string name, int age) {
		this->name = name;
		this->age = age;
	}
	~Single(){}
	int getAge() { return age; }
	string getName() { return name; }
protected:
	int age;
	string name;
};

