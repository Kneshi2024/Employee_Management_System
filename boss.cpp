#include"boss.h"

//���쾭����
Boss::Boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//����չʾ����
void Boss::ShowInfo() {
	cout << "Ա���ı��Ϊ:  " << this->m_Id
		<< "\tԱ��������Ϊ:  " << this->m_Name
		<< "\t��λΪ:  " << this->GetDeptName()
		<< "\t��λְ��:  �ƹܹ�˾ȫ������" << endl;
}

//������ȡ�������ƺ���
string Boss::GetDeptName() {
	return string("�ϰ�");
}