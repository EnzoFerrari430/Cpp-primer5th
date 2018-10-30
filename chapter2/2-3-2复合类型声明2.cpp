#include <iostream>

int main()
{
    int i = 42;
    int *p;  //p是int型指针
    int *&r = p;  //r是一个对指针p的引用
    //int *&r 从右往左阅读 离r最近的是& 因此r是一个引用，*表示r引用的是一个指针，最后int说明r引用的是一个int型指针

    r = &i;  //r引用了一个指针，因此给r赋值&i，就是将p指向i
    *r = 0; //使用解引用符号* 得到i将i的值改为0

    std::cout<<i<<std::endl;  //0
    std::cout<<*p<<std::endl; //0
    std::cout<<*r<<std::endl; //0

    const int buf = 512;
    //buf = 100;  const限定符的不能改变

    //const int c = get_size();

    return 0;
}
