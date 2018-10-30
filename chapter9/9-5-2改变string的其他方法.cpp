#include <iostream>
#include <vector>
#include <string>
using namespace std;
/*
    除了接受迭代器的insert和erase版本外，string还提供了接受下标版本。
    下标指出了开始删除的位置，或是insert到给定位置之前的位置
    s.insert(s.size(),5,'!');  在s末尾插入5个感叹号
    s.erase(s.size() - 5,5);   从s删除最后5个字符


string &insert(int p0, const char *s);——在p0位置插入字符串s

string &insert(int p0, const char *s, int n);——在p0位置插入字符串s的前n个字符

string &insert(int p0,const string &s);——在p0位置插入字符串s

string &insert(int p0,const string &s, int pos, int n);——在p0位置前插入字符串s从pos开始的连续n个字符

string &insert(int p0, int n, char c);//在p0处插入n个字符c
iterator insert(iterator it, char c);//在it处插入字符c，返回插入后迭代器的位置

void insert(iterator it, const_iterator first, const_iterator last);//在it处插入从first开始至last-1的所有字符

void insert(iterator it, int n, char c);//在it处插入n个字符c
*/
int main()
{
//标准库string类型还提供了接受C风格字符数组的insert和assign版本
    string s;
    const char *cp = "Stately,plump Buck";
    s.assign(cp,7);  //s == "Stately"
    s.insert(s.size(),cp + 7);
    cout<<s<<endl;

//我们也可以指定将来自其他string或子字符串的字符插入到当前string中或赋予当前string
    string ss = "some string",ss2 = "some other string";
    ss.insert(0,ss2);  //0位置之前插入s2的拷贝
    cout<<ss<<endl;
    ss.insert(0,ss2,0,ss2.size());  //在p0位置前插入字符串s从pos开始的连续n个字符
    cout<<ss<<endl;



    return 0;
}
