#include <iostream>
using namespace std;

//void change(int *p1,int *p2)  //指针类型形参不能改变地址
void change(int* &p1,int* &p2)  //形参变成指针类型的引用就可以改变指针的内容了
{
    int *temp = p1;
    p1 = p2;
    p2 = temp;
}


int main()
{
    int a1,a2;
    cin>>a1>>a2;
    int *p1 = &a1;
    int *p2 = &a2;
    cout<<&a1<<' '<<&a2<<endl;
    cout<<p1<<' '<<p2<<endl;
    //change(&a1,&a2);
    change(p1,p2);
    cout<<&a1<<' '<<&a2<<endl;  //没变
    cout<<p1<<' '<<p2<<endl;    //交换了
    cout<<a1<<' '<<a2<<endl;

    return 0;
}
