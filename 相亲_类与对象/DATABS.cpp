#include "DATABS.h"
#include <fstream>

#define BOY_FILE "boys.txt"
#define GIRL_FILE "girl.txt"

void DATABS::inti(){
	//��ʼ��,�������Ϣ
	intiBoyfile();
	intiGirlfile();
}

void DATABS::autopair(){
	cout << "***�Զ����***" << endl;
	string line(15, '*');
	cout << line << endl;
	//BOY��Girl��ƥ��
	for (int i = 0; i < boys.size(); i++) {
		for (int k = 0; k < girls.size(); k++) {
			if (boys[i].attitude(girls[k]) && girls[k].attitude(boys[i])) {
				cout << boys[i].print() << endl;
				cout << girls[k].print() <<endl;
				cout<<"����ƥ��!" << endl;
				cout << line << endl;
			}
		}
	}
	//Girl��BOY��ƥ��
	for (int i = 0; i < girls.size(); i++) {
		for (int k = 0; k < boys.size(); k++) {
			if (girls[i].attitude(boys[k]) && boys[k].attitude(girls[i])) {
				cout << girls[i].print() << endl;
				cout << boys[k].print() << endl;
				cout << "����ƥ��!" << endl;
				cout << line << endl;
			}
		}
	}
}

void DATABS::Greatpair(){
	cout << "***������***" << endl;
	string line(15, '*');
	cout << line << endl;
	//BOY��Girl��ƥ��
	for (int i = 0; i < boys.size(); i++) {
		Girl* Goodgirl = NULL;
		for (int k = 0; k < girls.size(); k++) {
			if (!Goodgirl) {
				Goodgirl = &girls[k];
			}
			else if (girls[k] > * Goodgirl) {
				Goodgirl = &girls[k];
			}
		}
		cout << boys[i] << endl;
		cout << *Goodgirl << endl;
		cout << "����ƥ��!" << endl;
		cout << line << endl;
	}
	//Girl��BOY��ƥ��
	for (int i = 0; i < girls.size(); i++) {
		Boy* Goodboy = NULL;
		for (int k = 0; k < boys.size(); k++) {
			if (Goodboy == NULL) {
				Goodboy = &boys[k];
			}
			else if (boys[k] > *Goodboy) {
				Goodboy = &boys[k];
			}
		}
		cout << girls[i] << endl;
		cout << *Goodboy << endl;
		cout << "����ƥ��!" << endl;
		cout << line << endl;
	}
}

void DATABS::print(){
	cout << "***��ͬ־��Ϣ***" << endl;
	for (int i = 0; i < boys.size(); i++) {
		cout << boys[i].print() << endl;
	}
	cout << "***Ůͬ־��Ϣ***" << endl;
	for (int i = 0; i < girls.size(); i++) {
		cout << girls[i].print() << endl;
	}
}

void DATABS::addOne(Boy& boy){
	boys.push_back(boy);//�ѵ�����Ϣ���浽�����ı���ȥ
	cout << "***�Զ����***" << endl;
	string line(15, '*');
	cout << line << endl;
		for (int k = 0; k < girls.size(); k++) {
			if (boy.attitude(girls[k]) && girls[k].attitude(boy)) {
				cout << boy.print() << endl;
				cout << girls[k].print() << endl;
				cout << "����ƥ��!" << endl;
				cout << line << endl;
			}
		}
	}

void DATABS::addOne(Girl& girl){
	girls.push_back(girl);
	cout << "***�Զ����***" << endl;
	string line(15, '*');
		for (int k = 0; k < boys.size(); k++) {
			if (girl.attitude(boys[k]) && boys[k].attitude(girl)) {
				cout << girl.print() << endl;
				cout << boys[k].print() << endl;
				cout << "����ƥ��!" << endl;
				cout << line << endl;
			}
		}
	}

void DATABS::intiBoyfile(){
	ifstream boyfile;
	boyfile.open(BOY_FILE);
	if (!boyfile) {
		//���ǵ��ʼʱ��û���ı���
		cout << "***���������û�����Ϣ***" << endl;
		Boy::inputBoys(this->boys);
		saveboy();
		boyfile.close();
		return;
	}
	//�ı��Ѿ�����
	while (1){
		string line;
		char name[64];
		int age, salary;
		getline(boyfile, line);
		if (boyfile.eof()) {
			break;
		}
		//����ʽ�����Ϣ,ret��ʾ��Ϣ������,�����ж�
		int ret = sscanf_s(line.c_str(), "����:%d ����:%s н��:%d", &age, name, sizeof(name), &salary);
		if (ret <= 0) {
			cout << "Boy���ļ���ʽƥ��ʧ��!" << endl;
			system("pause");
			exit(1);
		}
		boys.push_back(Boy(string(name),age,salary));
	}
	boyfile.close();
}

void DATABS::saveboy(){
	ofstream boyfile;
	boyfile.open(BOY_FILE);
	if (!boyfile) {
		cout << "BOY_FILE�ļ���ʧ��" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < boys.size(); i++) {
		boyfile<<boys[i].print() << endl;
	}
	boyfile.close();
}

void DATABS::intiGirlfile(){
	ifstream girlfile;
	girlfile.open(GIRL_FILE);
	if (!girlfile.is_open()) {
		cout << "***����Ů�û���Ϣ***" << endl;
		Girl::inputGirl(this->girls);
		savegilr();
		girlfile.close();
		return;
	}
	while (1){//�ж��ı��Ƿ����
		string line;
		char name[64];
		int age, looks;
		getline(girlfile, line);
		if (girlfile.eof()) {
			break;
		}
		//�����ַ���line�����Ϣ
		int ret = sscanf_s(line.c_str(), "����:%d ����:%s ��ֵ:%d",&age, name, sizeof(name), &looks);
		if (ret <= 0) {
			cout << "Girl�ļ���ȡʧ��!" << endl;
			break;
		}
		//����һ������,�Ѷ�������Ϣ���浽������ȥ;
		girls.push_back(Girl(string(name),age,looks));
	}
	girlfile.close();
}

void DATABS::savegilr(){
	ofstream girlfile;
	girlfile.open(GIRL_FILE);
	if (!girlfile.is_open()) {
		cout << "��girl.txt�ļ�ʧ��" << endl;
		system("pause");
		exit(1);
	}
	for (int i = 0; i < girls.size(); i++) {
		girlfile << girls[i].print() << endl;
	}
	girlfile.close();
}
