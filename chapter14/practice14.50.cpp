/*

    考点：
        二义性与转换目标为内置类型的多重类型转换

        产生二义性的根本原因是它们所需的标准类型转换级别一致。
        当使用用户定义的类型转换时，如果转换类型包含标准类型转换，则标准类型转换的级别将决定编译器选择最佳的匹配过程
*/
#include <iostream>
using namespace std;

struct LongDouble
{
    LongDouble(double = 0.0);
    operator double();
    operator float();
};

LongDouble ldObj;
int ex1 = ldObj;  //这句会产生二义性，double和float的类型转换运算符级别一样。
float ex2 = ldObj;  //这句使用float的类型转换运算符优先级高

int main()
{


    return 0;
}
