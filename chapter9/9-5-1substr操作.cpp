#include <iostream>
#include <string>
using namespace std;
/*
    substr操作返回一个string，它是原始string的一部分或全部的拷贝。可以传递给substr一个可选的位置和计数值
    子字符串操作
    s.substr(pos,n) 返回一个string，包含s中从pos开始的n个字符的拷贝。pos的默认值是0.n的默认值为s.size() - pos，即拷贝从pos开始的所有字符
*/
int main()
{
    string s("hello world");
    string s2 = s.substr(0,5);  //s2 == "hello"
    string s3 = s.substr(6);  //s3 == "world"
    string s4 = s.substr(6,11);  //s4 == "world"
    //string s5 = s.substr(12);  //out_of_range异常




    return 0;
}
