#include <iostream>
#include <string>
using namespace std;
int main()
{
    int i = 5;
    int j = 3;
    double d = 3.1;
    const string *ps;
    char *pc;
    void *pv;
    i *= static_cast<int>(d);
    cout<<i<<endl;

    //pv = (void *)ps;
    pv = const_cast<string *>(ps);

    //i = int(*pc);
    i = static_cast<int>(*pc);

    //pv = &d;
    pv = static_cast<void *>(&d);

    //pc = (char*)pv;
    pc = static_cast<char *>(pv);

    double slope = static_cast<double>(j/i);  //j/i被截断成int型这里转换成double型
    cout<<slope<<endl;   //为什么是-3
    double dd = (double)j/i;
    cout<<dd<<endl;

    cout<<static_cast<double>(3/15)<<endl;


    return 0;
}
