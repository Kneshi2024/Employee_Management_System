#pragma once
#include <iostream>
using namespace std;
#include "Worker.h"
#include"employ.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "filename.txt"


class WorkManger {
public:
	//���캯��
	WorkManger();

	//��ʾ��Ա����
	void Show_Menu();

	//�˳���������
	void ExitSystem();

	//���ӳ�Ա����
	void addperson();

	//����ְ�����ݵ��ļ�
	void save();

	//��������
	~WorkManger();

	//��¼ְ������
	int psnnum;

	//ְ������ָ��
	Worker** EmpArry;

	//��ʼ������
	bool FileisEmpty;

	//��ȡ�ļ��м�¼����
	int getpsnum();

	//��ʼ��Ա������
	void init_emp();

	//��ʾְ����Ա����
	void ShowEmp();

	//ɾ��ְ����Ϣ
	void Del_Emp();

	//�ж�ְ���Ƿ����
	int isExist(int id);

	//�޸�Ա����Ϣ
	void Mod_Emp();

	//����ְ����Ϣ
	void Find_Emp();

	//����ְ��ID
	void Sort_Emp();

	//���ְ����Ϣ
	void Clean_Emp();
};
