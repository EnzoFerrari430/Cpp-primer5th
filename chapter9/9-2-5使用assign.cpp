#include <iostream>
#include <vector>
#include <list>
using namespace std;
/*
    顺序容器(除array外)还定义了一个名为assign的成员，允许我们从一个不同但相容的类型赋值，或者从容器的一个子序列赋值。
    assign操作用参数所指定的元素(的拷贝)替换左边容器中的所有元素
*/
int main()
{
    list<string> names;
    vector<const char *> oldstyle;
    //names = oldstyle;  //error  容器的类型不匹配

    //将const char *转换为string
    names.assign(oldstyle.cbegin(),oldstyle.cend());
    //assign的调用将names中的元素替换为迭代器指定范围中的元素的拷贝。assign的参数决定了容器将有多少个元素以及他们的值都是什么
    //★注意！！  由于旧的元素被替换，因此传递给assign的迭代器不能指向调用assign的容器

    return 0;
}
