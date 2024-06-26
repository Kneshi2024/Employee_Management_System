#pragma once
#include"Worker.h"
using namespace std;


//声明员工函数
class Employ :public Worker{
public:
	//员工函数构造
	Employ(int id,string name,int did);

	//声明展示函数
	 virtual void ShowInfo();

	//声明获取部门名称函数
	 virtual string GetDeptName();
};