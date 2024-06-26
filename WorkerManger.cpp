#include"WorkManger.h"

WorkManger::WorkManger() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���ļ�

	//�ļ�������
	if (!ifs.is_open()) {
		//cout << "�ļ�������" << endl;
		//��ʼ����Ա����
		this->psnnum = 0;//��������
		this->EmpArry = NULL;//����ָ���ÿ�
		this->FileisEmpty = true;//�ж�Ϊ��
		ifs.close();
		return;
	}
	//�ļ����ڵ�û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��" << endl;(����)
		//��ʼ����Ա����
		this->psnnum = 0;//��������
		this->EmpArry = NULL;//����ָ���ÿ�
		this->FileisEmpty = true;//�ж�Ϊ��
		ifs.close();
		return;
	}

	//�ļ��������м�¼
	int num = this->getpsnum();
	//cout << "Ա��������Ϊ:  " << num << "��" << endl;(����)
	this->psnnum = num;
	//��ʼ��Ա��
	this->EmpArry = new Worker * [this->psnnum];
	//���ļ��е����ݴ浽������
	this->init_emp();

	//���Դ���
	/*for (int i = 0;i < this->psnnum;i++) {
		cout<< "ְ���ı��Ϊ:  " << this->EmpArry[i]->m_Id
			<< " ְ��������Ϊ:  " << this->EmpArry[i]->m_Name
			<< " ְ���Ĳ��ű��Ϊ:  " << this->EmpArry[i]->DeptId << endl;
	}*/

}

//����ʵ����ʾ����
void WorkManger::Show_Menu() {
	cout << "****************************************" << endl;
	cout << "*******  ��ӭʹ��ְ������ϵͳ!  ********" << endl;
	cout << "**********  0.�˳��������  ************" << endl;
	cout << "**********  1.����ְ����Ϣ  ************" << endl;
	cout << "**********  2.��ʾְ����Ϣ  ************" << endl;
	cout << "**********  3.ɾ����ְְ��  ************" << endl;
	cout << "**********  4.�޸�ְ����Ϣ  ************" << endl;
	cout << "**********  5.����ְ����Ϣ  ************" << endl;
	cout << "**********  6.���ձ������  ************" << endl;
	cout << "**********  7.��������ĵ�  ************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//�˳��������ʵ��
void WorkManger::ExitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ӳ�Ա��������ʵ��
void WorkManger::addperson() {
	cout << "������Ҫ��ӵ�����:" << endl;
	int addpsnum=0;
	cin >> addpsnum;
	if (addpsnum > 0) {
		//����ռ��С
		int newSize = this->psnnum + addpsnum;//�¿ռ��СΪԭ����ռ���������ռ��С
		//newspaceָ��ָ��worker*����
		Worker** newspace = new Worker * [newSize];
		if (this->EmpArry != NULL) {
			for (int i = 0;i < this->psnnum;i++) {
				newspace[i] = this->EmpArry[i];
			}
		}
		//�������ְ��
		for (int i = 0;i < addpsnum;i++) {
			int id;
			string name;
			int Select;
			cout << "�������" << i + 1 << "��" << "ְ���ı��Ϊ:" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��" << "ְ��������Ϊ:" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> Select;
			//����worker��Ա
			Worker* worker = NULL;//����ָ�루׼������������Ա��
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
			//�������ĳ�Ա�ŵ�������ȥ
			newspace[this->psnnum + i] = worker;
		}
		//�ͷ�ԭ�пռ�
		delete[] this->EmpArry;
		//���¿ؼ�ָ��
		this->EmpArry = newspace;
		//���������С
		this->psnnum = newSize;

		//�������ݵ��ļ�
		this->save();
		
		//�ж��ļ��ǿ�
		this->FileisEmpty = false;

		cout << "�ɹ����" << addpsnum << "����ְ��" << endl;
	}
	else {
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

//����ְ�����ݵ��ļ�
void WorkManger::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ���д�ļ���

	//������д�뵽�ļ���
	for (int i = 0;i < this->psnnum;i++) {
		ofs << this->EmpArry[i]->m_Id << " "
			<< this->EmpArry[i]->m_Name << " "
			<< this->EmpArry[i]->DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();
}

//��ʾְ����Ա����
void WorkManger::ShowEmp() {
	if (this->FileisEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;
	}
	else {
		for (int i = 0;i < this->psnnum;i++) {
			this->EmpArry[i]->ShowInfo();//�ӿ���ͨ�õģ�����ͬ������ô�ӡ��ͬ
		}
	}
	system("pause");
	system("cls");
}

//ɾ��ְ����Ϣ
void WorkManger::Del_Emp() {

	if (this->FileisEmpty) {
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else {
		cout << "������Ҫɾ����ְ�����" << endl;
		int id;
		cin >> id;
		int index = this->isExist(id);
		if (index != -1) {
			for (int i = index;i < this->psnnum - 1;i++) {
				this->EmpArry[i] = this->EmpArry[i + 1];
			}
			this->psnnum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	if (this->psnnum == 0) {//ŵΪ����bool���͸�Ϊtrue
		this->FileisEmpty = true;
	}
	system("pause");
	system("cls");

}

//�ж�ְ���Ƿ����
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

//�޸�Ա����Ϣ
void WorkManger::Mod_Emp() {
	if (this->FileisEmpty) {
		cout << "�ļ������ڻ�Ϊ��" << endl;
	}
	else {
		cout << "������Ҫ�޸ĵ��˵�ID" << endl;
		int id;
		cin >>id;
		int ret = this->isExist(id);
		if (ret != -1) {
			cout << "���ҵ�����" << endl;
			delete this->EmpArry[ret];
			int newid = 0;
			string newname = "";
			int newDepid = 0;
			cout << "�鵽" << id << "��ְ����������������ID��:  " << endl;
			cin >> newid;
			cout << "  ����������������:  " << endl;
			cin >> newname;
			cout << "  ��ѡ��������ְλ:  " << endl;
			cout << "1.ְ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
				cout << "������������������" << endl;
				break;
			}
			//���µ�������
			this->EmpArry[ret] = worker;
			cout << "�޸ĳɹ�" << endl;
			this->save();
		}
		else {
			cout << "���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ����Ϣ
void WorkManger::Find_Emp() {
	if (this->FileisEmpty) {
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else {
		cout << "��ѡ��Ҫ���ҵķ�ʽ:" << endl;
		cout << "1.��ID����" << endl;
		cout << "2.����������" << endl;
		int select;
		cin >> select;
		switch (select){
		case 1: {
			cout << "������Ҫ���ҵ�ְ��ID" << endl;
			int id;
			cin >> id;
			int ret = this->isExist(id);
			if (ret != -1) {
				cout << "�鵽���ˣ���ְ����Ϣ����:" << endl;
				this->EmpArry[ret]->ShowInfo();
			}
			else {
				cout << "���޴���" << endl;
			}
			break;
		}
		case 2: {
			cout << "������Ҫ���ҵ�ְ������" << endl;
			string name;
			cin >> name;
			bool Flag = false;
			for (int i = 0;i < this->psnnum;i++) {
				if (this->EmpArry[i]->m_Name == name) {
					cout << "�鵽���ˣ���ְ����Ϣ����:" << endl;
					Flag = true;
					this->EmpArry[i]->ShowInfo();
				}
			}
			if (Flag == false) {
				cout << "���޴���" << endl;
			}
			break;
		}
		default:
			cout << "����ʧ�ܣ���ѡ����ȷѡ��1��2" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//����ְ��ID
void WorkManger::Sort_Emp() {
	if (this->FileisEmpty) {
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ķ�ʽ:" << endl;
		cout << "1.��������" << endl;
		cout << "2.��������" << endl;
		int select;
		cin >> select;
		for (int i = 0;i < this->psnnum;i++) {
			int MaxorMinid = i;
			for (int j = 1 + i;j < this->psnnum;j++) {
				if (select == 1) {//����
					if (this->EmpArry[MaxorMinid]->m_Id > this->EmpArry[j]->m_Id) {
						MaxorMinid = j;
					}
				}
				else {//����
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
		cout << "����ɹ��������Ľ��Ϊ:  " << endl;
		this->save();
		this->ShowEmp();
	}
}

//���ְ����Ϣ
void WorkManger::Clean_Emp() {
	if (this->FileisEmpty) {
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else {
		cout << "�Ƿ�����ļ�" << endl;
		cout << "1.����ļ�" << endl;
		cout << "2.����" << endl;
		int select;
		cin >> select;
		if (select == 1) {
			ofstream ofs(FILENAME, ios::trunc);
			ofs.close();
			if (this->EmpArry!= NULL) {
				//ɾ������ÿ��ְ������
				for (int i = 0;i < this->psnnum;i++) {
					delete this->EmpArry[i];
					this->EmpArry[i] = NULL;
				}
				//ɾ����������ָ��
				delete[]this->EmpArry;
				this->EmpArry = NULL;
				this->psnnum = 0;//����Ԫ�ظ�������
				this->FileisEmpty = true;//�ж�Ϊ��
			}
			cout << "����ɹ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//��ȡ�ļ��м�¼����
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


//��ʼ��Ա������
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
				delete this->EmpArry[i];//��������ÿ��Ԫ�����
			}
		}
		delete[]this->EmpArry;//ɾ���������ָ��
		this->EmpArry = NULL;
	}
}