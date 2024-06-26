#include"boss.h"

//构造经理函数
Boss::Boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//声明展示函数
void Boss::ShowInfo() {
	cout << "员工的编号为:  " << this->m_Id
		<< "\t员工的姓名为:  " << this->m_Name
		<< "\t岗位为:  " << this->GetDeptName()
		<< "\t岗位职责:  掌管公司全部事务" << endl;
}

//声明获取部门名称函数
string Boss::GetDeptName() {
	return string("老板");
}