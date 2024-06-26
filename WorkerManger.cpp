#include"WorkManger.h"

WorkManger::WorkManger() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//读文件

	//文件不存在
	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;
		//初始化成员变量
		this->psnnum = 0;//人数置零
		this->EmpArry = NULL;//数组指针置空
		this->FileisEmpty = true;//判断为空
		ifs.close();
		return;
	}
	//文件存在但没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空" << endl;(测试)
		//初始化成员变量
		this->psnnum = 0;//人数置零
		this->EmpArry = NULL;//数组指针置空
		this->FileisEmpty = true;//判断为空
		ifs.close();
		return;
	}

	//文件存在且有记录
	int num = this->getpsnum();
	//cout << "员工的人数为:  " << num << "名" << endl;(测试)
	this->psnnum = num;
	//初始化员工
	this->EmpArry = new Worker * [this->psnnum];
	//将文件中的数据存到数组中
	this->init_emp();

	//测试代码
	/*for (int i = 0;i < this->psnnum;i++) {
		cout<< "职工的编号为:  " << this->EmpArry[i]->m_Id
			<< " 职工的姓名为:  " << this->EmpArry[i]->m_Name
			<< " 职工的部门编号为:  " << this->EmpArry[i]->DeptId << endl;
	}*/

}

//具体实现显示界面
void WorkManger::Show_Menu() {
	cout << "****************************************" << endl;
	cout << "*******  欢迎使用职工管理系统!  ********" << endl;
	cout << "**********  0.退出管理程序  ************" << endl;
	cout << "**********  1.增加职工信息  ************" << endl;
	cout << "**********  2.显示职工信息  ************" << endl;
	cout << "**********  3.删除离职职工  ************" << endl;
	cout << "**********  4.修改职工信息  ************" << endl;
	cout << "**********  5.查找职工信息  ************" << endl;
	cout << "**********  6.按照编号排序  ************" << endl;
	cout << "**********  7.清空所有文档  ************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//退出程序具体实现
void WorkManger::ExitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//增加成员函数具体实现
void WorkManger::addperson() {
	cout << "请输入要添加的人数:" << endl;
	int addpsnum=0;
	cin >> addpsnum;
	if (addpsnum > 0) {
		//计算空间大小
		int newSize = this->psnnum + addpsnum;//新空间大小为原数组空间加上新增空间大小
		//newspace指针指向worker*数组
		Worker** newspace = new Worker * [newSize];
		if (this->EmpArry != NULL) {
			for (int i = 0;i < this->psnnum;i++) {
				newspace[i] = this->EmpArry[i];
			}
		}
		//批量添加职工
		for (int i = 0;i < addpsnum;i++) {
			int id;
			string name;
			int Select;
			cout << "请输入第" << i + 1 << "个" << "职工的编号为:" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个" << "职工的姓名为:" << endl;
			cin >> name;
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> Select;
			//创建worker成员
			Worker* worker = NULL;//创建指针（准备堆区创建成员）
			switch (Select){
			case 1:
				worker = new Employ(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//将创建的成员放到数组中去
			newspace[this->psnnum + i] = worker;
		}
		//释放原有空间
		delete[] this->EmpArry;
		//更新控件指针
		this->EmpArry = newspace;
		//更新数组大小
		this->psnnum = newSize;

		//保存数据到文件
		this->save();
		
		//判断文件非空
		this->FileisEmpty = false;

		cout << "成功添加" << addpsnum << "名新职工" << endl;
	}
	else {
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}

//保存职工数据到文件
void WorkManger::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件（写文件）

	//将数据写入到文件中
	for (int i = 0;i < this->psnnum;i++) {
		ofs << this->EmpArry[i]->m_Id << " "
			<< this->EmpArry[i]->m_Name << " "
			<< this->EmpArry[i]->DeptId << endl;
	}
	//关闭文件
	ofs.close();
}

//显示职工成员函数
void WorkManger::ShowEmp() {
	if (this->FileisEmpty) {
		cout << "文件不存在或者记录为空" << endl;
	}
	else {
		for (int i = 0;i < this->psnnum;i++) {
			this->EmpArry[i]->ShowInfo();//接口是通用的，但不同对象调用打印不同
		}
	}
	system("pause");
	system("cls");
}

//删除职工信息
void WorkManger::Del_Emp() {

	if (this->FileisEmpty) {
		cout << "文件不存在或文件为空" << endl;
	}
	else {
		cout << "请输入要删除的职工编号" << endl;
		int id;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {
			for (int i = index;i < this->psnnum - 1;i++) {
				this->EmpArry[i] = this->EmpArry[i + 1];
			}
			this->psnnum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	if (this->psnnum == 0) {//诺为空则bool类型改为true
		this->FileisEmpty = true;
	}
	system("pause");
	system("cls");

}

//判断职工是否存在
int WorkManger::isExist(int id) {
	int index = -1;
	for (int i = 0;i < this->psnnum;i++) {
		if (this->EmpArry[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}

//修改员工信息
void WorkManger::Mod_Emp() {
	if (this->FileisEmpty) {
		cout << "文件不存在或为空" << endl;
	}
	else {
		cout << "请输入要修改的人的ID" << endl;
		int id;
		cin >>id;
		int ret = this->isExist(id);
		if (ret != -1) {
			cout << "查找到此人" << endl;
			delete this->EmpArry[ret];
			int newid = 0;
			string newname = "";
			int newDepid = 0;
			cout << "查到" << id << "号职工，请输入他的新ID号:  " << endl;
			cin >> newid;
			cout << "  请输入他的新姓名:  " << endl;
			cin >> newname;
			cout << "  请选择他的新职位:  " << endl;
			cout << "1.职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			int select=0;
			cin >> select;
			Worker* worker = NULL;
			switch (select){
			case 1:
				worker = new Employ(newid, newname, select);
				break;
			case 2:
				worker = new Manager(newid, newname, select);
				break;
			case 3:
				worker = new Boss(newid, newname, select);
				break;
			default:
				cout << "输入有误请重新输入" << endl;
				break;
			}
			//更新到数组中
			this->EmpArry[ret] = worker;
			cout << "修改成功" << endl;
			this->save();
		}
		else {
			cout << "查无此人" << endl;
		}
	}
	system("pause");
	system("cls");
}

//查找职工信息
void WorkManger::Find_Emp() {
	if (this->FileisEmpty) {
		cout << "文件不存在或文件为空" << endl;
	}
	else {
		cout << "请选择要查找的方式:" << endl;
		cout << "1.按ID查找" << endl;
		cout << "2.按姓名查找" << endl;
		int select;
		cin >> select;
		switch (select){
		case 1: {
			cout << "请输入要查找的职工ID" << endl;
			int id;
			cin >> id;
			int ret = this->isExist(id);
			if (ret != -1) {
				cout << "查到此人，该职工信息如下:" << endl;
				this->EmpArry[ret]->ShowInfo();
			}
			else {
				cout << "查无此人" << endl;
			}
			break;
		}
		case 2: {
			cout << "请输入要查找的职工姓名" << endl;
			string name;
			cin >> name;
			bool Flag = false;
			for (int i = 0;i < this->psnnum;i++) {
				if (this->EmpArry[i]->m_Name == name) {
					cout << "查到此人，该职工信息如下:" << endl;
					Flag = true;
					this->EmpArry[i]->ShowInfo();
				}
			}
			if (Flag == false) {
				cout << "查无此人" << endl;
			}
			break;
		}
		default:
			cout << "查找失败，请选择正确选项1或2" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//排序职工ID
void WorkManger::Sort_Emp() {
	if (this->FileisEmpty) {
		cout << "文件不存在或文件为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序的方式:" << endl;
		cout << "1.升序排序" << endl;
		cout << "2.降序排序" << endl;
		int select;
		cin >> select;
		for (int i = 0;i < this->psnnum;i++) {
			int MaxorMinid = i;
			for (int j = 1 + i;j < this->psnnum;j++) {
				if (select == 1) {//升序
					if (this->EmpArry[MaxorMinid]->m_Id > this->EmpArry[j]->m_Id) {
						MaxorMinid = j;
					}
				}
				else {//降序
					if (this->EmpArry[MaxorMinid]->m_Id < this->EmpArry[j]->m_Id) {
						MaxorMinid = j;
					} 
				}
			}
			if (i != MaxorMinid) {
				Worker* temp = this->EmpArry[i];
				this->EmpArry[i] = this->EmpArry[MaxorMinid];
				this->EmpArry[MaxorMinid] = temp;
			}
		}
		cout << "排序成功，排序后的结果为:  " << endl;
		this->save();
		this->ShowEmp();
	}
}

//清空职工信息
void WorkManger::Clean_Emp() {
	if (this->FileisEmpty) {
		cout << "文件不存在或文件为空" << endl;
	}
	else {
		cout << "是否清空文件" << endl;
		cout << "1.清空文件" << endl;
		cout << "2.返回" << endl;
		int select;
		cin >> select;
		if (select == 1) {
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();
			if (this->EmpArry!= NULL) {
				//删除堆区每个职工对象
				for (int i = 0;i < this->psnnum;i++) {
					delete this->EmpArry[i];
					this->EmpArry[i] = NULL;
				}
				//删除堆区数组指针
				delete[]this->EmpArry;
				this->EmpArry = NULL;
				this->psnnum = 0;//数组元素个数置零
				this->FileisEmpty = true;//判断为空
			}
			cout << "清除成功" << endl;
		}
	}
	system("pause");
	system("cls");
}

//获取文件中记录人数
int WorkManger::getpsnum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	int num = 0;
	string name;
	int Depid;
	while (ifs >> id && ifs >> name && ifs >> Depid) {
		num++;
	}
	ifs.close();
	return num;
	
}


//初始化员工函数
void WorkManger::init_emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int Depid;
	int index = 0;
	while (ifs>>id&&ifs>>name&&ifs>>Depid) {
		Worker* worker = NULL;
		if (Depid==1) {
			worker = new Employ(id, name, Depid);
		}
		else if (Depid==2) {
			worker = new Manager(id,name,Depid);
		}
		else {
			worker = new Boss(id, name, Depid);
		}
		this->EmpArry[index] = worker;
		index++;
	}
	ifs.close();
}

WorkManger::~WorkManger() {
	if (this->EmpArry != NULL) {
		for (int i = 0;i < this->psnnum;i++) {
			if (this->EmpArry[i] != NULL) {
				delete this->EmpArry[i];//把数组中每个元素清空
			}
		}
		delete[]this->EmpArry;//删除数组堆区指针
		this->EmpArry = NULL;
	}
}