#include <iostream>
#include <string>
using namespace std;
/*
    函数指针指向的是函数而非对象
    ★函数的类型由它的返回类型和形参类型共同决定，与函数名无关

    bool lengthCompare(const string &,const string &);

    该函数的类型是bool(const string &,const string &)
    想要声明一个可以指向该函数的指针，只需要用指针替换函数名即可
    bool (*pf)(const string &,const string &);  必须要括号

    指向不同函数类型的指针间不能转换，但是可以赋值nullptr和0表示空
*/
bool lengthCompare(const string &,const string &);


bool lengthCompare(const string &s1,const string &s2)
{
    return true;
}

bool (*pf)(const string &s1,const string &s2);
int main()
{
    pf = lengthCompare;  //pf指向名为lengthCompare的函数
    pf = &lengthCompare; //等价的赋值语句  取地址符是可选的

    //可以直接使用指向函数指针调用该函数，无需提前解引
    bool b1 = pf("hello","goodbye");              //调用lengthCompare函数
    bool b2 = (*pf)("hello","goodbye");           //一个等价的调用
    bool b3 = lengthCompare("hello","goodbye");   //另一个等价的调用

    pf = 0;

    return 0;
}
