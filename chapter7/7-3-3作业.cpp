#include <iostream>
using namespace std;

class Y;  //��ǰ��������Y

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
