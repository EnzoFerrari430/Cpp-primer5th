#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
内联函数和constexpr函数通常定义在头文件中,可以有多个定义，但是必须完全一致
    6.43a 放在头文件中，因为是inline函数
    6.43b 放在头文件中，普通函数也放在头文件中比较好

    6.46 不可以，isShorter的参数类型是string类型，不是字面值类型

*/
inline bool isShorter(const string &s1,const string &s2)
{
    return s1.size() < s2.size();
}
int main()
{


    return 0;
}
