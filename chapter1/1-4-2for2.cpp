#include <iostream>

int main()
{
    int sum,i;
    sum = 0;
    for(i = 50;i<=100;i++)
    {
        sum += i;
    }

    std::cout<<"the sum is: "<<sum<<std::endl;


    for(i = 1;i<= 10;i++)
    {
        std::cout<<i<<" ";
    }

    std::cout<<std::endl;

    for(i=10;i>=1;i--)
    {
        std::cout<<i<<" ";
    }

    std::cout<<std::endl;

    int v1,v2;
    std::cout<<"请用户输入2个整数"<<std::endl;

    std::cin>>v1>>v2;
    if(v1<v2)
    {
        for(;v1<=v2;v1++)
        {
            std::cout<<v1<<" ";
        }
    }
    else if(v1>v2)
    {
        for(;v2<=v1;v2++)
        {
            std::cout<<v2<<" ";
        }
    }
    else
    {
        std::cout<<v1<<" ";
    }


    return 0;
}
