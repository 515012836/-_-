#include <iostream>
#include <Windows.h>
#include <vector>
#include "Boy.h"
#include "Girl.h"

void autopair( vector<Boy>&boys,vector<Girl>&girls);//自动匹配

int main(void) {
	vector<Boy>boys;
	vector<Girl>girls;
	Boy::inputBoys(boys);
	Girl::inputGirl(girls);

	autopair(boys, girls);

	system("pause");
}

void autopair(vector<Boy>& boys,vector<Girl>& girls){
	for (int i = 0; i < boys.size(); i++) {
		for (int k = 0; k < girls.size(); k++) {
			if (boys[i].attitude(girls[k]) && girls[k].attitude(boys[i])) {
				cout << boys[i].print() << ",和  " << girls[k].print() << "   可以匹配!" << endl;
			}
		}
	}
}
