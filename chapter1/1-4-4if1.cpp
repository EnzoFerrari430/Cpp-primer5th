#include <iostream>

int main()
{
    //ͳ�����������˶��ٴ�
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
                std::cout<<"����"<<num1<<"������"<<cou<<"��"<<std::endl;
                num1 = num2;
                cou = 1;
            }
        }
        std::cout<<"����"<<num1<<"������"<<cou<<"��"<<std::endl;
    }


    return 0;

}
