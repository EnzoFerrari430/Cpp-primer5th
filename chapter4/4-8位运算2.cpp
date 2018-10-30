#include <iostream>
using namespace std;


/*
    位异或:对应位置上的值不相同异或结果是1，否则是0
    移位运算符的优先级不高也不低，比算术运算符优先级低 比关系运算符、赋值运算符、条件运算符优先级高
*/

int main()
{
    int i,j;
    i = 0;
    j = 1;

    cout<<(i^j)<<endl;

    //有些机器上unsigned int长度达不到16位
    unsigned long quiz1 = 0;
    //1ul 字面值是1的unsigned long类型
    quiz1 |= 1ul << 27;  //学生27通过了测验
    cout<<quiz1<<endl;

    quiz1 &= ~(1ul << 27);  //学生27没有通过测验
    cout<<quiz1<<endl;

    bool status = quiz1 & (1ul << 27); //学生27有没有通过测验
    cout<<status<<endl;



    return 0;
}
