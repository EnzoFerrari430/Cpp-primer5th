#include <iostream>


/*
const 对象被定义为仅在文件内有效
当多个文件一起出现了同名的const变量时，其实等同于在不同的文件中分别定义了独立的变量

想在多个文件内共享const对象，必须在变量的定义之前添加extern关键字

const对象在创建的时候一定要初始化
*/
int main()
{
    int i = 42;
    const int ci = i;  //正确，i值拷贝给了ci
    int j = ci;  //正确，ci值拷贝给了j


    return 0;
}
