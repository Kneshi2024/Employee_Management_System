#pragma once
#include<iostream>
using namespace std;

//声明Worker类
class Worker {
public:

	//声明展示函数
	virtual void ShowInfo() = 0;

		//声明获取部门名称函数
	virtual string GetDeptName() = 0;

	int m_Id;//编号
	string m_Name;//姓名
	int DeptId;//单位编号
};