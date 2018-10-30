#include <iostream>
#include <string>
using namespace std;
void reset(int &i)
{
    i = 0;
}

bool iSshorter(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}
int main()
{
    /*
        引用的操作实际上是作用在引用所引对象上
        引用形参的行为与之类似。通过使用引用形参，允许函数改变一个或多个实参的值
    */
    int n = 0, i = 42;
    int &r = n;  //r绑定了n
    r = 42;
    r = i;
    i = r;

    int j = 42;
    cout<<j<<endl;
    reset(j);
    cout<<j<<endl;

    /*
        使用引用避免拷贝
            拷贝大的类类型对象或者容器对象比较低效,有的类类型甚至不支持拷贝操作。当某种类型不支持拷贝操作时，函数只能通过引用访问

            比如编写比较2个string对象的长度，string对象可能会很长，这时要避免拷贝,而使用引用,又因为string不变，所以可以用对常量的引用
    */


    return 0;
}
