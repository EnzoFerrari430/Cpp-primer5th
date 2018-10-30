#include <iostream>
#include <string>
using namespace std;
//reinterpret_cast通常为运算对象的位模式提供较低层次上的重新解释
int main()
{
    int i = 84;  //ascii码84值是T
    char *c = reinterpret_cast<char *>(&i);
    int *ip = &i;
    char *pc = reinterpret_cast<char *>(ip);
    //pc所指的真实对象是一个int而非字符，如果把pc当成普通的字符指针使用可能就会发生错误
    string str(pc);
    cout<<&i<<endl;
    cout<<ip<<endl;
    cout<<pc<<endl;    //T
    cout<<*pc<<endl;   //T
    cout<<c<<endl;     //T
    cout<<*c<<endl;    //T


    return 0;
}
