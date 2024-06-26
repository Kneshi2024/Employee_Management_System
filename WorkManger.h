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
	//构造函数
	WorkManger();

	//显示成员函数
	void Show_Menu();

	//退出函数声明
	void ExitSystem();

	//增加成员函数
	void addperson();

	//保存职工数据到文件
	void save();

	//析构函数
	~WorkManger();

	//记录职工人数
	int psnnum;

	//职工数组指针
	Worker** EmpArry;

	//初始化属性
	bool FileisEmpty;

	//获取文件中记录人数
	int getpsnum();

	//初始化员工函数
	void init_emp();

	//显示职工成员函数
	void ShowEmp();

	//删除职工信息
	void Del_Emp();

	//判断职工是否存在
	int isExist(int id);

	//修改员工信息
	void Mod_Emp();

	//查找职工信息
	void Find_Emp();

	//排序职工ID
	void Sort_Emp();

	//清空职工信息
	void Clean_Emp();
};
