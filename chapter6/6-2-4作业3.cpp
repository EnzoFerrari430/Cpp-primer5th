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


//��ʾ����һ����ʾ��С���β�
void print(const int ia[],size_t size)
{
    for(size_t i = 0;i<size;++i)
        cout<<ia[i]<<' ';
    cout<<endl;
}

//��׼��淶
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
��������Ǵ����
������β�ʱһ�����飬�����ǲ��������ģ��������ǲ����Դ�ֵ�ķ�ʽʹ���������
Ҫ�ĳ����õķ�ʽ void print(const int (&ia)[10])
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
