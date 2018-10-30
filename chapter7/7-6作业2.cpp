#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Example
{
public:
    static constexpr double rate = 6.5;  //类内初始化静态成员，要求静态成员必须是字面值常量
    static constexpr int vecSize = 20;
    static vector<double> vec;  //类内不用确定大小
};

constexpr double Example::rate;  //在类的外部定义静态成员时不能重复static 要加constexpr
vector<double> Example::vec(Example::vecSize);
int main()
{


    return 0;
}
