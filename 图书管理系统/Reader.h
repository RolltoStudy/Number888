#pragma once
#include<iostream>
using namespace std;
#include"Identity.h"

	class Reader :public Identity {
	public:
		Reader();
		Reader(string Name, string Pwd);//�˻� ����
		virtual void operMenu();// �˵�		
		//����ͼ��
		void searchBook();
		//����
		void borrowBook();
		//����
		void returnBook();
	};

