#include"employ.h"

//��ͨԱ����������
Employ::Employ(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;

}

//����չʾ����
void Employ::ShowInfo() {
	cout << "Ա���ı��Ϊ:  " << this->m_Id 
		 << "\tԱ��������Ϊ:  " << this->m_Name 
		 << "\t��λΪ:  " << this->GetDeptName() 
		 << "\t��λְ��:  ��ɾ�����������" << endl;
 }

//�����ȡ�������ƺ���
string Employ::GetDeptName() {
	return string("ְ��");

 }