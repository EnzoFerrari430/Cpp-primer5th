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
    //ǰ�߽�����ת����const int,�ڽ���const intֵ�ĵط����ܹ�ʹ��
    //���߽�����ת����intֵ�������˵����ͨ��һЩ
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
