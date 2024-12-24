#pragma once//防止头文件重复包含
#include <iostream>
using namespace std;

class Identity {
	public:
		virtual void operMenu() = 0;
		string m_Name;
		string m_Pwd;
};


static string LogName;//记录当前登陆用户的用户名

class User
{
protected:
    string name;//用户姓名
    string key;//用户密码
    bool Is_Admin, Is_Librarian, Is_Reader;//什么用户类型
public:
    void key_change(User* U);//修改用户密码
    int  Judge();//判断用户类型
    static int User_Number;
    User() { Is_Admin = 0; Is_Librarian = 0; Is_Reader = 1; };//默认读者类型
    void Setname(string name1);
    void Setkey(string key1);
    void SetIdentity(bool ad, bool li, bool re)//设置用户类型
    {
        Is_Admin = ad; Is_Reader = re; Is_Librarian = li;
    }
    string Getname() { return name; }
    string Getkey() { return key; }
    bool GetisAd() { return Is_Admin; }
    bool Getisli() { return Is_Librarian; }
    bool Getisre() { return Is_Reader; }
};