#pragma once
#include<iostream>
using namespace std;
#include"Worker.h"

//声明老板类
class Boss:public Worker {

public:
	//构造经理函数
	Boss(int id, string name, int did);

	//声明展示函数
	virtual void ShowInfo();

	//声明获取部门名称函数
	virtual string GetDeptName();
};