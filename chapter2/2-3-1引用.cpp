#include <iostream>

int main()
{
    int ival = 1024;
    int &refval = ival;  //refval指向ival(是ival的另一个名字) ival的引用
    //int &refval2;  报错：引用必须被初始化
    //int &refval2 = 100;  报错必须要一个对象



    //double pi = 3.14;
    //int &ri = pi;  报错引用类型的初始值必须是int型对象

    refval = 2;
    int ii = refval;

    int &refval3 = refval;  //正确refval3绑定到了那个与refval绑定的对象上就是ival上
    int i = refval;  //正确，i被初始化为ival的值

    /*
    std::cout<<"ival "<<ival<<std::endl;

    std::cout<<"refval "<<refval<<std::endl;
    std::cout<<"ii "<<ii<<std::endl;
    */


    return 0;
}
