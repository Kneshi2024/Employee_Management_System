#pragma once
#include"Worker.h"
using namespace std;


//����Ա������
class Employ :public Worker{
public:
	//Ա����������
	Employ(int id,string name,int did);

	//����չʾ����
	 virtual void ShowInfo();

	//������ȡ�������ƺ���
	 virtual string GetDeptName();
};