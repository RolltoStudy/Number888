#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"
#include<string>

	class Adm :public Identity {
	public:
		Adm();
		Adm(string Name, string pwd);
		virtual void operMenu();// 菜单	
		//用户管理
		void addUser();
		void deleteUser();
		void editUser();
		void searchUser();
		void resetPwd();
		//图书管理
		void addBook();
		void deleteBook();
		void editBook();
		void searchBook();

	};
