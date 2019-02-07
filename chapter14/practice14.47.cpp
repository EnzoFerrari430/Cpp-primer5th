#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Integral
{
    Integral(int i):val(i){
        if(val < 0)
        {
            throw out_of_range("the value is negative number");
        }
    }
    //前者将对象转换成const int,在接受const int值的地方才能够使用
    //后者将对象转换成int值，相对来说更加通用一些
    operator const int(){return val;}
    operator int()const{return val;}

    std::size_t val;
};

int add(int i,int j)
{
    return i + j;
}

int add2(const int i,const int j)
{

    return i + j;
}
int main()
{
    cout<<add(Integral(1),Integral(2))<<endl;
    cout<<add2(Integral(1),Integral(2))<<endl;

    return 0;
}
