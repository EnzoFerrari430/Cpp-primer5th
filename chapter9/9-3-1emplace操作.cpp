#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
/*
    C++11新标准引入了三个新成员 —— emplace_front,emplace,emplace_back，这些操作构造而不是拷贝元素，对应push_front,insert,push_back

    在调用push或insert成员函数时，我们将元素类型的对象传递给它们，这些对象被拷贝到容器中。
    当调用emplace成员函数时，则是将参数传递给元素类型的构造函数。emplace成员使用这些参数在容器管理的内存空间中直接构造元素

    emplace函数的参数根据元素类型而变化，参数必须与元素类型的构造函数想匹配
*/
int main()
{
    //iter指向c中的一个元素，其中保存了Sales_data元素
    c.emplace_back();  //使用Sales_data的默认构造函数
    c.emplace(iter,"999-999999999");  //使用Sales_data(string)
    //使用Sales_data的接受一个ISBN、一个count和一个price的构造函数
    c.emplace_front("978-0590353403",25,15.99);

    return 0;
}
