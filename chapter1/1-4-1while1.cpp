#include <iostream>

int main()
{
    int sum,i;
    i=50;
    sum = 0;
    while(i<=100)
    {
        sum += i;
        i++;
    }
    std::cout<<"the sum of 50 to 100 is: "<<sum<<std::endl;


    return 0;
}
