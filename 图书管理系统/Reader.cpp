#include"Reader.h"
Reader::Reader() {

}
//�˺� ����
Reader::Reader(string Name, string Pwd) {
	this->m_Name = Name;
	this->m_Pwd = Pwd;
}
//�˵�
void  Reader::operMenu() {
	cout<<"��ӭ����"<<this->m_Name<<endl;
	cout << "1 ����ͼ��" << endl;
	cout << "2 ����" << endl;
	cout << "3 ����" << endl;
	cout << "��ѡ�����Ĳ���" << endl;
}
//����
void Reader::searchBook() {

}
//����
void Reader::borrowBook() {

}
//����
void Reader::returnBook() {

}

//�޸�����
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
    cout << "������ԭ����:";
    cin >> key;
    if (key == U[find].Getkey())
    {
        cout << "������������:";
        cin >> key;
        cout << "������һ��������:";
        cin >> key1;
        if (key == key1)
        {
            U[find].Setkey(key);
            cout << "�޸ĳɹ���" << endl;
        }
        else
        {
            cout << "�����������벻һ��,�޸�ʧ��!" << endl;
        }
    }
    else
    {
        cout << "�������" << endl;
    }
}