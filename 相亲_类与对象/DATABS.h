#pragma once
/*
ʹ���ļ������û���Ϣ
����:��ʼ���û���Ϣ,�Զ����,��ӡ����;
����:���������
*/
#include <vector>
#include "Boy.h"
#include "Girl.h"

class DATABS{
public:
	DATABS(){}
	~DATABS(){}
	//��ʼ��
	void inti();
	//�Զ����
	void autopair();
	//������
	void Greatpair();
	//��ӡ����
	void print();
	//�����к���Ů���������Ϣ
	void addOne(Boy&boy);
	void addOne(Girl&girl);
private:
	//��������Ϣ
	vector<Boy>boys;
	//����Ů��Ϣ
	vector<Girl>girls;
	//�����е��ı�
	void intiBoyfile();
	void saveboy();//���浥������Ϣ���ı�
	//����Ů���ı�
	void intiGirlfile();
	void savegilr();//���浥��Ů��Ϣ���ı�
};

