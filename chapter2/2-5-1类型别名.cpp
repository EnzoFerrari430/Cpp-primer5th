#include <iostream>
using namespace std;
/*
    类型别名是某种类型的同义词

*/
//传统方法
typedef double wages;  //wages是double的同义词
typedef wages base,*p;  //base是double的同义词，p是double*的同义词

//C++11 新方法 别名声明
//using 声明开始后面紧跟 别名和等号 把等号左边的名字规定成右边类型的别名
//using SI = Sales_item;  //SI是Sales_item的同义词
using SI = int;  //SI是Sales_item的同义词

//指针，常量和类型别名
/*
    如果类型别名指代的是复合类型或常量 声明语句会产生不一样的效果
*/
//类型pString是char*的别名
typedef char *pString;
int main()
{
    wages hours;
    //pString str = new char;
    //cin>>str;
    //cout<<str<<endl;

    char c = 42;
    char d = 2;
    //类比一下 const int i; int型的常量 pString指向char的指针
    const pString cstr1 = &c;  //指向char的常量指针  const后面跟的直接是cstr1 所以是常量 pString已经复合了指针 所以是常量指针
    const char *cstr2 = &c;  //上下2种不是一样的！！！！！  指向const char的指针
    //delete(str);
    return 0;
}
