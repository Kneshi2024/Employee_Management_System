//#include<iostream>  没必要加 与 WorkerManger中的重复
using namespace std;
#include"WorkManger.h"
#include"Worker.h"
#include"employ.h"
#include"manager.h"
#include"boss.h"




int main() {

	////员工测试
	//Worker* worker = NULL;
	//worker = new Employ(1, "张三", 1);
	//worker->ShowInfo();
	//delete worker;

	////经理测试
	//worker = new Manager(2, "李四", 2);
	//worker->ShowInfo();
	//delete worker;

	////老板测试
	//worker = new Boss(3, "王五", 3);
	//worker->ShowInfo();
	//delete worker;



	WorkManger wm;
	int choice = 1;

	while (choice) {
		wm.Show_Menu();
		cout << "请输入相应的序号" << endl;
		cin >> choice;
	
		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.addperson();
			break;
		case 2:
			wm.ShowEmp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		case 7:
			wm.Clean_Emp();
			break;
		default:
			system("cls");
			break;
		}
	}
	

	system("pause");
	return(0);
}