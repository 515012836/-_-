#pragma once
/*
使用文件保存用户信息
功能:初始化用户信息,自动配对,打印功能;
数据:单身的数据
*/
#include <vector>
#include "Boy.h"
#include "Girl.h"

class DATABS{
public:
	DATABS(){}
	~DATABS(){}
	//初始化
	void inti();
	//自动配对
	void autopair();
	//最佳配对
	void Greatpair();
	//打印功能
	void print();
	//单个男孩和女孩的配对信息
	void addOne(Boy&boy);
	void addOne(Girl&girl);
private:
	//单身男信息
	vector<Boy>boys;
	//单身女信息
	vector<Girl>girls;
	//单身男的文本
	void intiBoyfile();
	void saveboy();//保存单身男信息的文本
	//单身女的文本
	void intiGirlfile();
	void savegilr();//保存单身女信息的文本
};

