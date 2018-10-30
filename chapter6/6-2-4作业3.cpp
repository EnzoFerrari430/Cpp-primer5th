#include <iostream>
using namespace std;
void print(int *p)
{
    if(p)
        cout<<*p<<endl;
}

void print(const char *p)
{
    if(p)
        while(*p)
            cout<<*p++<<' ';
    cout<<endl;
}


//显示传递一个表示大小的形参
void print(const int ia[],size_t size)
{
    for(size_t i = 0;i<size;++i)
        cout<<ia[i]<<' ';
    cout<<endl;
}

//标准库规范
void print(const int *beg,const int *end)
{
    while(beg != end)
        cout<< *beg++<<' ';
    cout<<endl;
}

void print(const int (&arr)[2])
{
    for(auto elem:arr)
        cout<<elem<<' ';
    cout<<endl;
}
/*
6.24
这个函数是错误的
这里的形参时一个数组，数组是不允许拷贝的，所以我们不能以传值的方式使用数组参数
要改成引用的方式 void print(const int (&ia)[10])
void print(const int ia[10])
{
    for(size_t i = 0;i != 10; ++i)
        cout<<ia[i]<<endl;
}
*/

int main()
{
    int i = 0;
    int j[2] = {6,66};
    char code[6] = "hello";


    print(&i);
    print(j,sizeof(j)/4);
    print(begin(j),end(j));
    print(code);
    print(const_cast<const int(&)[2]>(j));

    return 0;
}
