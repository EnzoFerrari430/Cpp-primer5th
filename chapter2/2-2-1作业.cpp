#include <iostream>

/*
嵌套的作用域
作用域中一旦声明了某个名字，它所嵌套的所有作用域中都能访问该名字
同时，允许内层作用域中重新定义外层作用域已有的名字


*/
std::string global_str;
int global_int;


int main()
{
    //std::cin>> int input_value;  错误 int 之前的表达式有错误
    //int i = {3.14};  成功 精度丢失 变成i = 3
    //double salary = wage = 9999.99;  错误 wage未定义
    //int i = 3.14;    成功 精度丢失 变成i = 3
    //std::cout<<i<<std::endl;

    //int global_int;
    //std::string global_str;

    std::cout<<global_int<<std::endl;
    std::cout<<global_str<<std::endl;

    return 0;
}
