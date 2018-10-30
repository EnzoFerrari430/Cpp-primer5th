#include <iostream>

int main()
{
    //std::cout<<sizeof('a')<<std::endl;  //1
    //std::cout<<sizeof("a")<<std::endl;  //2 多个了\0

    /*
        通过*的个数可以区分指针的级别
        **表示指向指针的指针 2级指针
        ***表示指向指针的指针的指针  3级指针...

    */
    int ival = 1024;
    int *pi = &ival; //指向一个int型的数
    int **ppi = &pi; //指向一个int型的指针

    std::cout<<"the value of ival\n"
    <<"direct value: "<<ival<<"\n"
    <<"indirect value: "<<*pi<<"\n"
    <<"double indirect value: "<<**ppi<<std::endl;

    std::cout<<pi<<std::endl;
    std::cout<<ppi<<std::endl;



    return 0;
}
