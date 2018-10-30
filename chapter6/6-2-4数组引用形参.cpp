#include <iostream>
using namespace std;

void print(int (&arr)[10])
{
    for(auto elem : arr)
    {
        cout<<elem<<endl;
    }
}
//但是这用写法限制了print函数的可用性，我们只能将函数作用于大小为10的数组
//&arr 两端的括号必不可少
//f(int &arr[10])      //wrong 将arr声明成了引用的数组
//f(int (&arr)[10])    //bingo arr是具有10个整数的整型数组的引用
int main()
{
    int i = 0;
    int j[2] = {0,1};
    int k[10] = {0,1,2,3,4,5,6,7,8,9};
    //print(&i);  //实参不是含有10个整数的数组
    //print(j);   //实参不是含有10个整数的数组
    print(k);


    return 0;
}
