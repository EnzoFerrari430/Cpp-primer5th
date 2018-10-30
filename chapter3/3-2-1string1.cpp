#include <iostream>
using std::string;

int main()
{
    /*
        直接初始化和拷贝初始化,使用"="的是拷贝初始化，不使用的是直接初始化
    */
    string s1;  //默认初始化为空
    string s2 = s1;
    string s3 = "hiya";
    string s4(10,'c');
    //std::cout<<s1<<"\n"<<s2<<"\n"<<s3<<"\n"<<s4<<"\n";

    string s7(10,'c');
    string s8 = string(10,'c');  //效果和s7一样但是可读性较差
    std::cout<<s7<<std::endl;
    std::cout<<s8<<std::endl;
    return 0;
}
