#include <iostream>

int main()
{
    /*
    int ival = 1.01;
    //int &rval1 =  1.01;  //不能是字面值常量
    int &rval2 = ival;
    //int &rval3;  定义必须初始化一个对象
    */

    int i = 0,&r1 = i;
    double d = 0,&r2 = d;
    r2 = 3.14159;
    std::cout<<"r2 "<<r2<<std::endl;
    std::cout<<"d "<<d<<std::endl;
    r2 = r1;
    i = r2;
    r1 = d;
    std::cout<<"i "<<i<<std::endl;
    std::cout<<"r1 "<<r1<<std::endl;
    std::cout<<"d "<<d<<std::endl;
    std::cout<<"r2 "<<r2<<std::endl;

    return 0;
}
