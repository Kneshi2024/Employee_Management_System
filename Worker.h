#pragma once
#include<iostream>
using namespace std;

//����Worker��
class Worker {
public:

	//����չʾ����
	virtual void ShowInfo() = 0;

		//������ȡ�������ƺ���
	virtual string GetDeptName() = 0;

	int m_Id;//���
	string m_Name;//����
	int DeptId;//��λ���
};