#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>
using namespace std;

class Identity {
	public:
		virtual void operMenu() = 0;
		string m_Name;
		string m_Pwd;
};


static string LogName;//��¼��ǰ��½�û����û���

class User
{
protected:
    string name;//�û�����
    string key;//�û�����
    bool Is_Admin, Is_Librarian, Is_Reader;//ʲô�û�����
public:
    void key_change(User* U);//�޸��û�����
    int  Judge();//�ж��û�����
    static int User_Number;
    User() { Is_Admin = 0; Is_Librarian = 0; Is_Reader = 1; };//Ĭ�϶�������
    void Setname(string name1);
    void Setkey(string key1);
    void SetIdentity(bool ad, bool li, bool re)//�����û�����
    {
        Is_Admin = ad; Is_Reader = re; Is_Librarian = li;
    }
    string Getname() { return name; }
    string Getkey() { return key; }
    bool GetisAd() { return Is_Admin; }
    bool Getisli() { return Is_Librarian; }
    bool Getisre() { return Is_Reader; }
};