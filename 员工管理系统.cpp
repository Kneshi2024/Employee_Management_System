//#include<iostream>  û��Ҫ�� �� WorkerManger�е��ظ�
using namespace std;
#include"WorkManger.h"
#include"Worker.h"
#include"employ.h"
#include"manager.h"
#include"boss.h"




int main() {

	////Ա������
	//Worker* worker = NULL;
	//worker = new Employ(1, "����", 1);
	//worker->ShowInfo();
	//delete worker;

	////�������
	//worker = new Manager(2, "����", 2);
	//worker->ShowInfo();
	//delete worker;

	////�ϰ����
	//worker = new Boss(3, "����", 3);
	//worker->ShowInfo();
	//delete worker;



	WorkManger wm;
	int choice = 1;

	while (choice) {
		wm.Show_Menu();
		cout << "��������Ӧ�����" << endl;
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