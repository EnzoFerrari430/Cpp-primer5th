#include <iostream>
#include <string>
using namespace std;
/*
s.compare的几种参数形式
s2                      比较s和s2

pos1,n1,s2              将s中从pos1开始的n1个字符与s2进行比较

pos1,n1,s2,pos2,n2      将s中从pos1开始的n1个字符与s2中从pos2开始的n2个字符进行比较

cp                      比较s与cp指向的以空字符结尾的字符数组

pos1,n1,cp              将s中从pos1开始的n1个字符与cp指向的以空字符结尾的字符数组进行比较

pos1,n1,cp,n2           将s中从pos1开始的n1个字符与指针cp指向的地址开始的n2个字符进行比较

*/

int main()
{
    string str("helloworld");
    cout<<str.compare("hElloworld")<<endl;



    return 0;
}
