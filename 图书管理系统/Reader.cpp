#include"Reader.h"
Reader::Reader() {

}
//账号 密码
Reader::Reader(string Name, string Pwd) {
	this->m_Name = Name;
	this->m_Pwd = Pwd;
}
//菜单
void  Reader::operMenu() {
	cout<<"欢迎读者"<<this->m_Name<<endl;
	cout << "1 搜索图书" << endl;
	cout << "2 借书" << endl;
	cout << "3 还书" << endl;
	cout << "请选择您的操作" << endl;
}
//搜索
void Reader::searchBook() {

}
//借书
void Reader::borrowBook() {

}
//还书
void Reader::returnBook() {

}

//修改密码
void User::key_change(User* U)
{
    int find = 0; string key, key1;
    for (int i = 0; i < User::User_Number; i++)
    {
        if (U[i].Getname() == LogName)
        {
            find = i; break;
        }
    }
    cout << "请输入原密码:";
    cin >> key;
    if (key == U[find].Getkey())
    {
        cout << "请输入新密码:";
        cin >> key;
        cout << "再输入一次新密码:";
        cin >> key1;
        if (key == key1)
        {
            U[find].Setkey(key);
            cout << "修改成功！" << endl;
        }
        else
        {
            cout << "两次密码输入不一致,修改失败!" << endl;
        }
    }
    else
    {
        cout << "密码错误！" << endl;
    }
}