#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>

	class Adm :public Identity {
	public:
		Adm();
		Adm(string Name, string pwd);
		virtual void operMenu();// �˵�	
		//�û�����
		void addUser();
		void deleteUser();
		void editUser();
		void searchUser();
		void resetPwd();
		//ͼ�����
		void addBook();
		void deleteBook();
		void editBook();
		void searchBook();

	};
