#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"

	class Reader :public Identity {
	public:
		Reader();
		Reader(string Name, string Pwd);//账户 密码
		virtual void operMenu();// 菜单		
		//搜索图书
		void searchBook();
		//借书
		void borrowBook();
		//还书
		void returnBook();
	};

