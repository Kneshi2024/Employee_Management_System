#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//����������
class Manager:public Worker {

public:

	//���쾭����
	Manager(int id, string name, int did);

	//����չʾ����
	virtual void ShowInfo();

	//������ȡ�������ƺ���
	virtual string GetDeptName();
};
