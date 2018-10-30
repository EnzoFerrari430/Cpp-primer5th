#include <iostream>
#include <string>
using namespace std;

/*
new 的缺陷： 内存分配和对象构造组合到了一起，delete将对象析构和释放内存放到了一起
在分配大块内存时，这种将内存分配和对象构造组合在一起可能会导致不必要的浪费

    更重要的是，那些没有默认构造函数的类就不能动态分配内存数组了
*/
int main()
{
    string *const p = new string[10];
    string s;
    string *q = p;
    //可能不需要这么多的string,造成了浪费
    while(cin>>s && q != p+10)
    {
        *q = s;
        q++;
    }
    const size_t size = q - p;
    cout<<size<<endl;


    delete[] p;





    return 0;
}
