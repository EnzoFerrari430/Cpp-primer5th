#include <iostream>

int main()
{
    //统计数字输入了多少次
    int num1,num2;
    num1 = num2 = 0;
    if(std::cin>>num1)
    {
        int cou = 1;
        while(std::cin>>num2)
        {
            if(num1 == num2)
            {
                cou++;
            }
            else
            {
                std::cout<<"数字"<<num1<<"出现了"<<cou<<"次"<<std::endl;
                num1 = num2;
                cou = 1;
            }
        }
        std::cout<<"数字"<<num1<<"出现了"<<cou<<"次"<<std::endl;
    }


    return 0;

}
