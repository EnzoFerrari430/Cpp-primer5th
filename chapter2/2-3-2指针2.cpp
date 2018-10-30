#include <iostream>
#include <cstdlib>


int main()
{
    int *p1 = nullptr;  //C++11标准
    int *p2 = 0;
    int *p3 = NULL;

    std::cout<<p1<<std::endl;
    std::cout<<p2<<std::endl;
    std::cout<<p3<<std::endl;

    //void *指针可以存放任意对象的地址,也可以存放任意类型的指针
    //void *指针值能做有限的事情,不能直接操作void *指针所指的对象
    double obj = 3.14,*pd = &obj;
    void *pv = &obj;
    pv = pd;


    return 0;
}
