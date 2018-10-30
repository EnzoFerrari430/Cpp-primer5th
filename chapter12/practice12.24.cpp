#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <memory>
using namespace std;
/*

    超出长度的话，后面的字符会被截断
*/
int main()
{
    int size{0};
    //cout<<size<<endl;
    cin>>size;
    char *p = new char[size+1];  //因为后面会跟一个'\0'
    cin.ignore();  //忽略上一个字符
    cout<<"input the string: ";
    cin.get(p,size+1);
    cout<<p<<endl;


    delete[] p;

    //12.25
    int *pa = new int[10];
    delete[] pa;
    return 0;
}
