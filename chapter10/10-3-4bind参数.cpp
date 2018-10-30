#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>
using namespace std;
using namespace std::placeholders;

/*
    可以用bind绑定给定可调用对象中的参数或重新安排其顺序
    假定f是一个可调用对象，它有5个参数，则下面对bind的调用
    g是一个有2个参数的可调用对象
    auto g = bind(f,a,b,_2,c,_1);
    生成新的可调用对象，它有2个参数，分别用占位符_2和_1表示。这个新的可调用对象将它自己的参数作为第三个和第五个参数传递给f。
    f的第一个、第二个和第四个参数分别被绑定到给定值a、b和c上
*/

int main()
{


    return 0;
}
