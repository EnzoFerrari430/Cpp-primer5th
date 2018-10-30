#include <iostream>

int main()
{
    int ival = 42;
    int *p = &ival;
    //int &refval = ival;
    //int *pp = &refval;  引用不是对象，没有实际的地址值，所以不能定义指向引用的指针
    std::cout<<*p<<std::endl;  //*是解引用符 由符号*得到指针p所指的对象
    std::cout<<p<<std::endl;
    *p = 10;  //由符号*得到指针p所指的对象，可经由p为变量ival赋值
    std::cout<<ival<<std::endl;


    double dval = 3.14;
    double *pd = &dval;
    double *pd2 = pd;  //初始值是指向double对象的指针，pd的内容是dval的地址
    double **pd3 = &pd;

    //int *pi = pd;  //指针pi的类型和pd不匹配
    //pi = &dval;  //double型对象的地址不能赋值给int型指针

    std::cout<<pd<<" "<<*pd<<std::endl;
    std::cout<<pd2<<" "<<*pd2<<std::endl;
    std::cout<<pd2<<" "<<&pd2<<std::endl;
    std::cout<<pd3<<" "<<**pd3<<std::endl;



    return 0;
}
