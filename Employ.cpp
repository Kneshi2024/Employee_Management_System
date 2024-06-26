#include"employ.h"

//普通员工函数构造
Employ::Employ(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;

}

//具体展示函数
void Employ::ShowInfo() {
	cout << "员工的编号为:  " << this->m_Id 
		 << "\t员工的姓名为:  " << this->m_Name 
		 << "\t岗位为:  " << this->GetDeptName() 
		 << "\t岗位职责:  完成经理交给的任务" << endl;
 }

//具体获取部门名称函数
string Employ::GetDeptName() {
	return string("职工");

 }