#include <iostream>

int main()
{
/*
    指向常量的指针(pointer to const)不能用于改变其所指对象的值
    想要存放常量对象的地址，只能使用指向常量的指针

    这个指针自以为指向的是常量,但是是不是常量还是要看指向的对象原来是不是常量
*/
    const double pi = 3.14;  //pi是常量不能改变
    //double *ptr = &pi;  //错误 ptr是一个普通指针
    const double *cptr = &pi;  //正确，cptr可以指向一个双进度常量
    // *cptr是常量 但是cptr不是常量可以改变
    //*cptr = 42;
    std::cout<<pi<<std::endl;
    std::cout<<*cptr<<std::endl;
    std::cout<<cptr<<std::endl;
    cptr += 1;
    std::cout<<pi<<std::endl;
    std::cout<<*cptr<<std::endl;
    std::cout<<cptr<<std::endl;

/*
指针的类型必须与其所指对象的类型一致
但是有2和例外
1.允许令一个指向常量的指针指向一个非常量对象

*/
    double dval = 3.1415;
    const double *rd = &dval;  //能通过但是不能用rd指针改变dval的值
    //const int *rd2 = &dval;  //类型不对
    //*rd = 3.1;  wrong
    dval = 3.1;  //right
    std::cout<<dval<<std::endl;
    std::cout<<*rd<<std::endl;

    rd = rd+1;
    std::cout<<*rd<<std::endl;
    rd = rd+1;
    std::cout<<*rd<<std::endl;





    return 0;
}
