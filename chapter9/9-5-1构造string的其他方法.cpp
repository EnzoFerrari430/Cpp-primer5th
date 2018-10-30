#include <iostream>
#include <string>
using namespace std;
/*
构造string的其他方法
n、len2和pos2都是无符号值    unsigned

方法1  string s(cp,n)          s是cp指向的数组中前n个字符的拷贝。此数组至少应该包含n个字符

方法2  string s(s2,pos2)       s是string s2从下标pos2开始的字符的拷贝。若pos2>s2.size(),构造函数的行为未定义

方法3  string s(s2,pos2,len2)  s是string s2从下标pos2开始len2个字符的拷贝。若pos2>s2.size()，构造函数的行为未定义。
                        不管len2的值是多少，构造函数至多拷贝s2.size()-pos2个字符

*/
int main()
{
    const char *cp = "hello world!!!";  //以空字符结束的数组
    char noNULL[] = {'H','i'};  //不以空字符结束
    string s1(cp);  //拷贝cp中的字符直到遇到空字符； s1 == "hello world!!!"
    string s2(noNULL,2);  //方法1
    string s3(noNULL);  //可以通过，但是因为noNULL没有空字符，所以会停止在一个有空字符的地方
    string s4(cp + 6,5);  //方法1
    string s5(s1,6,5);  //方法3
    string s6(s1,6);  //方法2
    string s7(s1,6,20);  //方法3
    //string s8(s1,16);  //异常 out_of_range



    return 0;
}
