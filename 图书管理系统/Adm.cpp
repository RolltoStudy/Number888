#include"Adm.h"
#include "globalfile.h"
#include <fstream>


Adm::Adm() {

}
Adm::Adm(string Name, string pwd) {
	this->m_Name = Name;
	this->m_Pwd = pwd;
}
void Adm::operMenu() {//�˵�
	cout << "��ӭ����Ա" << this->m_Name << endl;
	cout << "1 ����û�" << endl;
	cout << "2 ɾ���û�" << endl;
	cout << "3 �༭�û�" << endl;
	cout << "4 �����û�" << endl;
	cout << "5 ��������" << endl;
	cout << "6 ���ͼ��" << endl;
	cout << "7 ɾ��ͼ��" << endl;
	cout << "8 �༭ͼ��" << endl;
	cout << "9 ����ͼ��" << endl;
	cout<<"��ѡ�����Ĳ���"<<endl;
}
//�û�����
void Adm::addUser() {
	cout << "��������ӵ��˺�" << endl;
	string name;
	cin >> name;
	cout << "��������ӵ�����" << endl;
	string pwd;
	cin >> pwd;
	ofstream ofs;
	ofs.open(READER_FILE, ios::app);
	if (ofs.is_open()) {
		ofs << name << " " << pwd << endl;
		cout << "��ӳɹ�" << endl;
		ofs.close();
	}
	else {
		cout << "�ļ���ʧ��" << endl;
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
//ͼ�����
void Adm::addBook() {
	cout << "������ͼ����" << endl;
	string name;
	cin >> name;
	cout << "������ISBN/ISSN" << endl;
	string id;
	cin >> id;
	cout << "����������" << endl;
	string author;
	cin >> author;
	cout << "�����������" << endl;
	string press;
	cin >> press;
	cout << "������۸�" << endl;
	double price;
	cin >> price;
	cout << "����������" << endl;
	int num;
	cin >> num;
	cout << "����������" << endl;
	string type;
	cin >> type;
	cout << "������ͼ����" << endl;
	string summary;
	cin >> summary;
	ofstream ofs;
	ofs.open(BOOKINFORMATION_FILE, ios::app);
	if (ofs.is_open()) {
		ofs << name << " " << id << endl;
		cout << "��ӳɹ�" << endl;
		ofs.close();
	}
	else {
		cout << "�ļ���ʧ��" << endl;
	}
}
void Adm::deleteBook() {

}
void Adm::editBook() {

}
void Adm::searchBook() {

}