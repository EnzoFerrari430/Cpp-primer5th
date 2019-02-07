#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
/*

    标准库定义了一组表示算数运算符、关系运算符和逻辑运算符的类。每个类分别定义了一个执行命名操作的调用对象

*/



int main()
{
    plus<int> intAdd;  //可以执行int加法的函数对象
    negate<int> intNegate;  //可以对int值取反的函数对象

    int sum = intAdd(10,20);
    cout<<sum<<endl;
    sum = intNegate(intAdd(10,20));
    cout<<sum<<endl;

    //默认的sort排序算法使用operator<将序列按照升序排列。
    //如果要执行降序的话，可以传入一个greater类型的对象。该类将产生一个调用运算符并负责执行待排序类型的大于运算。
    vector<string> svec;
    //传入一个临时的函数对象用于执行两个string对象的>比较运算
    sort(svec.begin(),svec.end(),greater<string>());

    vector<string *> nameTable;  //指针的vector
    //错误： nameTable中的指针彼此之间没有关系，所以<将产生未定义的行为
    sort(nameTable.begin(),nameTable.end(),[](string *a,string *b){return a < b;});
    //正确： 标准库规定指针的less是定义良好的。
    sort(nameTable.begin(),nameTable.end(),less<string *>());




    return 0;
}
