#include <iostream>

int reused = 42;  //全局作用域
int main()
{
    int unique = 0;  //块作用域
    std::cout<<reused<<" "<<unique<<std::endl;

    int reused = 0;  //覆盖了全局变量
    std::cout<<reused<<" "<<unique<<std::endl;
    //显示访问全局变量  ::作用域操作符 左侧为空时 向全局作用域发出请求
    std::cout<<::reused<<" "<<unique<<std::endl;


    return 0;
}
