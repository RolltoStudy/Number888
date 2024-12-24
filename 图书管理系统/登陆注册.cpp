#include <iostream>
#include<fstream>
#include<string>
using namespace std;
#include"Identity.h"
#include"globalfile.h"
#include"Adm.h"
#include"Reader.h"
//���߽���
void ReaderMenu(Identity*& reader) {
	while (true) {
		reader->operMenu();//���ö��߲˵�
		Reader* read = (Reader*)reader;//����ָ��ת��Ϊ����
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "����ͼ��" << endl;
			read->searchBook();
		}
		else if (select == 2) {
			cout << "����" << endl;
			read->borrowBook();
		}
		else if (select == 3) {
			cout << "����" << endl;
			read->returnBook();
		}
	}
}
//����Ա����
void AdmMenu(Identity*& adm) {
	while (true) {
		adm->operMenu();//���ù���Ա�˵�
		Adm* admin = (Adm*)adm;//����ָ��ת��Ϊ����
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "����û�" << endl;
			admin->addUser();
		}
		else if (select == 2) {
			cout << "ɾ���û�" << endl;
			admin->deleteUser();
		}
		else if (select == 3) {
			cout << "�༭�û�" << endl;
			admin->editUser();
		}
		else if (select == 4) {
			cout << "�����û�" << endl;
			admin->searchUser();
		}
		else if (select == 5) {
			cout << "��������" << endl;
			admin->resetPwd();
		}
		else if (select == 6) {
			cout << "���ͼ��" << endl;
			admin->addBook();
		}
		else if (select == 7) {
			cout << "ɾ��ͼ��" << endl;
			admin->deleteBook();
		}
		else if (select == 8) {
			cout << "�༭ͼ��" << endl;
			admin->editBook();
		}
		else if (select == 9) {
			cout << "����ͼ��" << endl;
			admin->searchBook();
		}
	}
}

void Login(string fileName, int type) {
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout<<"�ļ�������"<<endl;
		ifs.close(); return;
	}
	string name;
	string pwd;
	if (type == 1) {//����Ա
		cout << "���������Ա�˺�" << endl;
		cin >> name;
		cout << "����������" << endl;
		cin >> pwd;
	}
	else if (type == 2) {//����
		cout << "����������˺�"<<endl;
		cin >> name;
		cout << "����������" << endl;
		cin >> pwd;
	}
	//��֤
	if (type == 1) {//����Ա��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "��¼�ɹ�" << endl;
				person = new Adm(name, pwd);
				AdmMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {//������֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "��¼�ɹ�" << endl;
				person = new Reader(name, pwd);
				ReaderMenu(person);
				return;
			}
		}
	}
	cout << "��½ʧ��" << endl;
	return ;
}

int main() {
	int select = 0;
	while (true) {
		cout << "��ӭ����HNUͼ���" << endl;
		cout << "1 ����Ա��¼\n";
		cout << "2 ���ߵ�¼\n";////////ע��ûд
		cout << "0 �˳�\n";
		cin >> select;
		switch (select) {
     case 1:
      Login(ADMIN_FILE, 1);
      break;
     case 2:
      Login(READER_FILE, 2);
      break;
     case 0:
      cout << "��ӭ�´�ʹ��"<<endl;
      return 0;
      break;
     default:
      cout << "��Ч��ѡ������������" << endl;
      break;
		}
	}
	return 0;
}




//��¼ע��
class Log
{
public:
	User tp;//�洢��½�ɹ����û�����Ϣ
	int number;//�洢��ǰ�û���Ϣ��Ӧ��User�����±�ֵ
	void Login(User* p);//��½
	void SignIN(User* p);//ע��
	Log() { number = 0; };
	bool Is_Log;//�ж��Ƿ��½�ɹ���
};

void Log::SignIN(User* p)
{
	int f1; string a, b, bb;
	while (1)
	{
		f1 = 1;
		cout << "�������û�����";
		cin >> a;
		for (int i = 0; i <= User::User_Number; i++)
		{
			if (p[i].Getname() == a)
			{
				cout << "�û����Ѵ��ڣ�����������." << endl; f1 = 0;
			}
		}
		if (f1 == 0) {};
		if (f1 == 1) { break; }
	}
	while (1)
	{
		cout << "����������:";
		cin >> b;
		cout << "�ٴ���������:";
		cin >> bb;
		if (bb != b)
		{
			cout << "�������벻һ�£�����������." << endl;
		}
		if (bb == b)
		{
			break;
		}
	}
	//��ע��ɹ����û���Ϣ�洢��user���
	(p + User::User_Number)->Setname(a);
	(p + User::User_Number)->Setkey(b);
	(p + User::User_Number)->SetIdentity(0, 0, 1);
	tp.Setname(a);
	number = User::User_Number;
	User::User_Number++;
};
void Log::Login(User* p)
{
	string a, b; int flag = 0;
	cout << "�������˺�:" << endl;
	cin >> a;
	cout << "����������:" << endl;
	cin >> b;
	for (int i = 0; i < User::User_Number; i++)
	{
		if (a == p[i].Getname() && b == p[i].Getkey())
		{
			tp.SetIdentity(p[i].GetisAd(), p[i].Getisli(), p[i].Getisre());
			flag = 1; tp.Setname(a); tp.Setkey(b); number = i; break;
		}
	}
	if (flag)
	{
		if (tp.Judge() == 7)
		{
			LogName = tp.Getname();
			cout << "��½�ɹ���" << endl; Is_Log = true;
			cout << "�𾴵Ķ���" << tp.Getname() << ",���ã�" << endl;
		}
		else if (tp.Judge() == 5)
		{
			LogName = tp.Getname();
			cout << "��½�ɹ���" << endl; Is_Log = true;
			cout << "�𾴵�ͼ�����Ա" << tp.Getname() << ",���ã�" << endl;
		}
		else if (tp.Judge() == 6)
		{
			LogName = tp.Getname();
			cout << "��½�ɹ���" << endl; Is_Log = true;
			cout << "�𾴵�ϵͳ����Ա" << tp.Getname() << ",���ã�" << endl;
		}
	}
	else { cout << "�˺Ż��������" << endl; Is_Log = false; }
}
