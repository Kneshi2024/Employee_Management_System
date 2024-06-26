#include"manager.h"


//构造经理函数
Manager::Manager(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//声明展示函数
 void Manager::ShowInfo() {
	 cout << "员工的编号为:  " << this->m_Id
		 << "\t员工的姓名为:  " << this->m_Name
		 << "\t岗位为:  " << this->GetDeptName()
		 << "\t岗位职责:  完成老板交给的任务，并安排员工工作" << endl;
}

//声明获取部门名称函数
 string Manager::GetDeptName() {
	 return string("经理");
}