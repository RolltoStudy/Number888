#pragma once
#include<iostream>
#include<iomanip> // ��Ӵ����԰��� setw �Ķ���
using namespace std;
#include<string>
class Book {
    protected:
        string ISBN, name, author, press, time;
        int deadline;//��������
        double price;//�۸�
        bool Is_Lend;//���Ƿ񱻽��
    public:
        static int Book_Number;
        Book(string name, string ISBN, string author, string press, double price);
        Book() { Is_Lend = false; }
        string Gettime() { return time; }
        string GetCode() { return ISBN; }
        string GetName() { return name; }
        string GetAuthor() { return author; }
        string GetPress() { return press; }
        int GetDeadline() { return deadline; }
        double GetPrice() { return price; }
        bool GetIs_Lend() { return Is_Lend; }
        void SetDeadline(int);
        void SetTime(string);
        void SetIs_Lend(bool);
        void SetCode(string);
        void SetName(string);
        void SetAuthor(string);
        void SetPress(string);
        void SetPrice(float);
        void Display();
        friend const std::string getCurrentSystemTime();//��ȡ���ڵ�ʱ��
        friend istream& operator >> (istream& stream, Book& b);//���ز�����>>
        friend ostream& operator << (ostream& stream, Book& b);//���ز�����<<
    };
    ostream& operator << (ostream& stream, Book& b)
    {
        stream << "����" << setw(9) << b.name << " ISBN:" << setw(9)
            << b.ISBN<< " ����:" << setw(9) << b.author << " ������:"
            << setw(9) << b.press << " ����:" << setw(5) << b.price << endl;
        return stream;
    }
    istream& operator >> (istream& stream, Book& b)
    {
        cout << "��������:";
        stream >> b.ISBN;
        cout << "����������:";
        stream >> b.name;
        cout << "������������:";
        stream >> b.author;
        cout << "�����������:";
        stream >> b.press;
        cout << "�����뵥��:";
        stream >> b.price;
        return stream;
    };
void Book::SetDeadline(int a) { deadline = a; }
void Book::SetTime(string a) { time = a; }
void Book::SetIs_Lend(bool a) { Is_Lend = a; }
void Book::Display()//����չʾ�������
{
    cout << "���" << setw(9) << GetCode() << " ����:" << setw(9)
        << GetName() << " ����:" << setw(9) << GetAuthor() << " ������:"
        << setw(9) << GetPress() << " ����:" << setw(5) << GetPrice() << " ����ʱ��:"
        << setw(10) << Gettime() << " ��������:" << GetDeadline() << "��" << endl;
}
void Book::SetCode(string code1)
{
   ISBN = code1;
}
void Book::SetName(string name1)
{
    name = name1;
}
void Book::SetAuthor(string author1)
{
    author = author1;
}
void Book::SetPress(string press1)
{
    press = press1;
}
void Book::SetPrice(float price1)
{
    price = price1;
}
int Book::Book_Number = 0;