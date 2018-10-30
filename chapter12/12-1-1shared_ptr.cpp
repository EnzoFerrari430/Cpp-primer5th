#include <iostream>
#include <memory>  //定义了shared_ptr unique_ptr weak_ptr
#include <string>
#include <list>
using namespace std;
/*
    类似vector，智能指针也是模板,需要在尖括号中给出指针可以指向的类型
*/
int main()
{
    shared_ptr<string> p1;      //可以指向string
    shared_ptr<list<int>> p2;   //可以指向int的list

    if(p1)
    {
        cout<<"p1指针不为空"<<endl;
        if(p1->empty())
        {
            cout<<"p1指针指向为空"<<endl;
        }
    }
    else
    {
        cout<<"p1指针为空"<<endl;
    }

    return 0;
}
