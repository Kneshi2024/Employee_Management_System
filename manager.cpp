#include"manager.h"


//���쾭����
Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//����չʾ����
 void Manager::ShowInfo() {
	 cout << "Ա���ı��Ϊ:  " << this->m_Id
		 << "\tԱ��������Ϊ:  " << this->m_Name
		 << "\t��λΪ:  " << this->GetDeptName()
		 << "\t��λְ��:  ����ϰ彻�������񣬲�����Ա������" << endl;
}

//������ȡ�������ƺ���
 string Manager::GetDeptName() {
	 return string("����");
}