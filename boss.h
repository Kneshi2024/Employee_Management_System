#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//�����ϰ���
class Boss:public Worker {

public:
	//���쾭����
	Boss(int id, string name, int did);

	//����չʾ����
	virtual void ShowInfo();

	//������ȡ�������ƺ���
	virtual string GetDeptName();
};