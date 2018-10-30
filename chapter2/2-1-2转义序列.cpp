#include <iostream>
#include <typeinfo>
#include <string>
#include <limits>

//2类字符不能直接使用
//1.不可打印的字符 退格，其他控制字符
//2.特殊含义的字符

/*
\n 换行符 \t 横向制表符 \a 报警符 \v 纵向制表符
\b 退格符 \" 双引号 \\ 反斜杠 \? 问号 \'单引号
\r 回车符 \f 进纸符
*/

template<class T>

char *judge(T a)
{
    return typeid(a).name();
}

int main()
{
    std::cout<<'\n';
    std::cout<<"\tHi!\n";  //输出一个制表符 输出一个Hi 输出一个换行符

    std::cout<<"Hi \x4dO\115!\n";  //输出Hi MOM，转到新一行   \x4d 是16进制 4d是十进制的77 M的asc码  115是8进制也是10进制的77
    //8进制数字最多只有3个参与转义  \1155表示是M5  而\x后面的数字都要参与转义

    //std::cout<<"\x1235\n";  //输出错误,char只占8位

    //std::cout<<sizeof(char)<<std::endl;  //char占一个字节 8位

    return 0;
}
