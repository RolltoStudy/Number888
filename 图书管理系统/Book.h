#pragma once
#include<iostream>
#include<iomanip> // 添加此行以包含 setw 的定义
using namespace std;
#include<string>
class Book {
    protected:
        string ISBN, name, author, press, time;
        int deadline;//借书期限
        double price;//价格
        bool Is_Lend;//书是否被借出
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
        friend const std::string getCurrentSystemTime();//获取现在的时间
        friend istream& operator >> (istream& stream, Book& b);//重载操作符>>
        friend ostream& operator << (ostream& stream, Book& b);//重载操作符<<
    };
    ostream& operator << (ostream& stream, Book& b)
    {
        stream << "书名" << setw(9) << b.name << " ISBN:" << setw(9)
            << b.ISBN<< " 作者:" << setw(9) << b.author << " 出版社:"
            << setw(9) << b.press << " 单价:" << setw(5) << b.price << endl;
        return stream;
    }
    istream& operator >> (istream& stream, Book& b)
    {
        cout << "请输入编号:";
        stream >> b.ISBN;
        cout << "请输入书名:";
        stream >> b.name;
        cout << "请输入作者名:";
        stream >> b.author;
        cout << "请输入出版社:";
        stream >> b.press;
        cout << "请输入单价:";
        stream >> b.price;
        return stream;
    };
void Book::SetDeadline(int a) { deadline = a; }
void Book::SetTime(string a) { time = a; }
void Book::SetIs_Lend(bool a) { Is_Lend = a; }
void Book::Display()//用来展示借书情况
{
    cout << "编号" << setw(9) << GetCode() << " 书名:" << setw(9)
        << GetName() << " 作者:" << setw(9) << GetAuthor() << " 出版社:"
        << setw(9) << GetPress() << " 单价:" << setw(5) << GetPrice() << " 借书时间:"
        << setw(10) << Gettime() << " 借书期限:" << GetDeadline() << "天" << endl;
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