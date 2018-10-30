#include <iostream>
#include <string>
#include <vector>
using namespace std;

//引用返回左值
char &get_val(string &str,string::size_type ix)
{
    return str[ix];    //get_val假定索引值是有效的
}

//列表初始化返回值
vector<string> process()
{
    string expected("hello");
    string actual("world");
    if( expected.empty())
        return {};    //返回一个空vector对象
    else if( expected == actual )
        return {"functionx","okay"};  //返回列表初始化的vector对象
    else
        return {"functionx",expected,actual};
}

int main()
{
    /*
        返回一个值的方式和初始化一个变量或形参的方式一样：返回的值用于初始化调用点的一个临时量，该临时量就是函数调用的结果

        ★★不要返回局部对象的引用或指针：函数完成后，它所占用的存储空间也随之被释放掉。
        因此，函数终止意味着局部变量的引用将指向不再有效的内存区域

        函数的返回类型决定函数调用是否是左值,调用一个返回引用的函数得到左值,其他返回类型得到右值
        特别的，我们能为返回类型是非常量引用的函数的结果赋值


        C++11新标准规定,函数可以返回花括号包围的值的列表.类似于其他返回结果，此处的列表也用来表示函数的返回的临时量进行初始化
    */
    string s("a value");
    cout<<s<<endl;
    get_val(s,0) = 'A';  //得到s[0] 并将其该为'A'
    cout<<s<<endl;


    return 0;
}
