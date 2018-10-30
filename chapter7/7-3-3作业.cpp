#include <iostream>
using namespace std;

class Y;  //提前声明类型Y

class X
{
    int num;

    Y *p;
};

class Y
{
    int data;
    X valx;
};
int main()
{


    return 0;
}
