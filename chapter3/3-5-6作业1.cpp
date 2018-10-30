#include <iostream>
using namespace std;
int main()
{
    int ia[3][4] = {0};  //初始化都是0
    //范围for的外层都要是引用
    for(int (&row)[4]:ia)
    {
        //引用的是4个元素
        for(int col:row)
        {
            cout<<col<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<4; j++)
        {
            cout<<ia[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
    for(int (*p)[4] = ia;p!= ia +3;p++)
    {
        for(int *q = *p;q!= *p +4;q++)
        {
            cout<<*q<<' ';
        }
        cout<<endl;
    }
    return 0;
}
