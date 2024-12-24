#include"Adm.h"
#include "globalfile.h"
#include <fstream>


Adm::Adm() {

}
Adm::Adm(string Name, string pwd) {
	this->m_Name = Name;
	this->m_Pwd = pwd;
}
void Adm::operMenu() {//菜单
	cout << "欢迎管理员" << this->m_Name << endl;
	cout << "1 添加用户" << endl;
	cout << "2 删除用户" << endl;
	cout << "3 编辑用户" << endl;
	cout << "4 查找用户" << endl;
	cout << "5 重置密码" << endl;
	cout << "6 添加图书" << endl;
	cout << "7 删除图书" << endl;
	cout << "8 编辑图书" << endl;
	cout << "9 查找图书" << endl;
	cout<<"请选择您的操作"<<endl;
}
//用户管理
void Adm::addUser() {
	cout << "请输入添加的账号" << endl;
	string name;
	cin >> name;
	cout << "请输入添加的密码" << endl;
	string pwd;
	cin >> pwd;
	ofstream ofs;
	ofs.open(READER_FILE, ios::app);
	if (ofs.is_open()) {
		ofs << name << " " << pwd << endl;
		cout << "添加成功" << endl;
		ofs.close();
	}
	else {
		cout << "文件打开失败" << endl;
	}
}


void Adm::deleteUser() {

}
void Adm::editUser() {

}
void Adm::searchUser() {

}
void Adm::resetPwd() {

}
//图书管理
void Adm::addBook() {
	cout << "请输入图书名" << endl;
	string name;
	cin >> name;
	cout << "请输入ISBN/ISSN" << endl;
	string id;
	cin >> id;
	cout << "请输入作者" << endl;
	string author;
	cin >> author;
	cout << "请输入出版社" << endl;
	string press;
	cin >> press;
	cout << "请输入价格" << endl;
	double price;
	cin >> price;
	cout << "请输入数量" << endl;
	int num;
	cin >> num;
	cout << "请输入类型" << endl;
	string type;
	cin >> type;
	cout << "请输入图书简介" << endl;
	string summary;
	cin >> summary;
	ofstream ofs;
	ofs.open(BOOKINFORMATION_FILE, ios::app);
	if (ofs.is_open()) {
		ofs << name << " " << id << endl;
		cout << "添加成功" << endl;
		ofs.close();
	}
	else {
		cout << "文件打开失败" << endl;
	}
}
void Adm::deleteBook() {

}
void Adm::editBook() {

}
void Adm::searchBook() {

}