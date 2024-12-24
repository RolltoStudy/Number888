#include <iostream>
#include<fstream>
#include<string>
using namespace std;
#include"Identity.h"
#include"globalfile.h"
#include"Adm.h"
#include"Reader.h"
//读者界面
void ReaderMenu(Identity*& reader) {
	while (true) {
		reader->operMenu();//调用读者菜单
		Reader* read = (Reader*)reader;//父类指针转化为子类
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "搜索图书" << endl;
			read->searchBook();
		}
		else if (select == 2) {
			cout << "借书" << endl;
			read->borrowBook();
		}
		else if (select == 3) {
			cout << "还书" << endl;
			read->returnBook();
		}
	}
}
//管理员界面
void AdmMenu(Identity*& adm) {
	while (true) {
		adm->operMenu();//调用管理员菜单
		Adm* admin = (Adm*)adm;//父类指针转化为子类
		int select = 0;
		cin >> select;
		if (select == 1) {
			cout << "添加用户" << endl;
			admin->addUser();
		}
		else if (select == 2) {
			cout << "删除用户" << endl;
			admin->deleteUser();
		}
		else if (select == 3) {
			cout << "编辑用户" << endl;
			admin->editUser();
		}
		else if (select == 4) {
			cout << "查找用户" << endl;
			admin->searchUser();
		}
		else if (select == 5) {
			cout << "重置密码" << endl;
			admin->resetPwd();
		}
		else if (select == 6) {
			cout << "添加图书" << endl;
			admin->addBook();
		}
		else if (select == 7) {
			cout << "删除图书" << endl;
			admin->deleteBook();
		}
		else if (select == 8) {
			cout << "编辑图书" << endl;
			admin->editBook();
		}
		else if (select == 9) {
			cout << "查找图书" << endl;
			admin->searchBook();
		}
	}
}

void Login(string fileName, int type) {
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);
	if (!ifs.is_open()) {
		cout<<"文件不存在"<<endl;
		ifs.close(); return;
	}
	string name;
	string pwd;
	if (type == 1) {//管理员
		cout << "请输入管理员账号" << endl;
		cin >> name;
		cout << "请输入密码" << endl;
		cin >> pwd;
	}
	else if (type == 2) {//读者
		cout << "请输入读者账号"<<endl;
		cin >> name;
		cout << "请输入密码" << endl;
		cin >> pwd;
	}
	//验证
	if (type == 1) {//管理员验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "登录成功" << endl;
				person = new Adm(name, pwd);
				AdmMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {//读者验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd) {
			if (fName == name && fPwd == pwd) {
				cout << "登录成功" << endl;
				person = new Reader(name, pwd);
				ReaderMenu(person);
				return;
			}
		}
	}
	cout << "登陆失败" << endl;
	return ;
}

int main() {
	int select = 0;
	while (true) {
		cout << "欢迎来到HNU图书馆" << endl;
		cout << "1 管理员登录\n";
		cout << "2 读者登录\n";////////注册没写
		cout << "0 退出\n";
		cin >> select;
		switch (select) {
     case 1:
      Login(ADMIN_FILE, 1);
      break;
     case 2:
      Login(READER_FILE, 2);
      break;
     case 0:
      cout << "欢迎下次使用"<<endl;
      return 0;
      break;
     default:
      cout << "无效的选择，请重新输入" << endl;
      break;
		}
	}
	return 0;
}




//登录注册
class Log
{
public:
	User tp;//存储登陆成功的用户的信息
	int number;//存储当前用户信息对应的User类中下标值
	void Login(User* p);//登陆
	void SignIN(User* p);//注册
	Log() { number = 0; };
	bool Is_Log;//判断是否登陆成功。
};

void Log::SignIN(User* p)
{
	int f1; string a, b, bb;
	while (1)
	{
		f1 = 1;
		cout << "请输入用户名：";
		cin >> a;
		for (int i = 0; i <= User::User_Number; i++)
		{
			if (p[i].Getname() == a)
			{
				cout << "用户名已存在，请重新输入." << endl; f1 = 0;
			}
		}
		if (f1 == 0) {};
		if (f1 == 1) { break; }
	}
	while (1)
	{
		cout << "请设置密码:";
		cin >> b;
		cout << "再次输入密码:";
		cin >> bb;
		if (bb != b)
		{
			cout << "两次密码不一致，请重新输入." << endl;
		}
		if (bb == b)
		{
			break;
		}
	}
	//将注册成功的用户信息存储到user类里。
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
	cout << "请输入账号:" << endl;
	cin >> a;
	cout << "请输入密码:" << endl;
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
			cout << "登陆成功！" << endl; Is_Log = true;
			cout << "尊敬的读者" << tp.Getname() << ",您好！" << endl;
		}
		else if (tp.Judge() == 5)
		{
			LogName = tp.Getname();
			cout << "登陆成功！" << endl; Is_Log = true;
			cout << "尊敬的图书管理员" << tp.Getname() << ",您好！" << endl;
		}
		else if (tp.Judge() == 6)
		{
			LogName = tp.Getname();
			cout << "登陆成功！" << endl; Is_Log = true;
			cout << "尊敬的系统管理员" << tp.Getname() << ",您好！" << endl;
		}
	}
	else { cout << "账号或密码错误！" << endl; Is_Log = false; }
}
