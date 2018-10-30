#include <iostream>
#include <string>
#include <memory>
using namespace std;
/*
    不能拷贝unique_ptr的规则有一个例外：我们可以拷贝或赋值一个将要销毁的unique_ptr。
*/

unique_ptr<int> clone(int p)
{
    return unique_ptr<int>(new int(p));
}

//还可以返回一个局部对象的拷贝
unique_ptr<int> clone_object(int p)
{
    unique_ptr<int> ret(new int(p));
    return ret;
}

int main()
{


    return 0;
}
