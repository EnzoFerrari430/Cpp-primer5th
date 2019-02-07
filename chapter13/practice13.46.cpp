#include <iostream>
#include <vector>
using namespace std;


int f();

int f()
{
    return 1;
}


vector<int> vi(100);


int &&r1 = f();  //  f()  返回的是临时的int  所以是右值
int &r2 = vi[0];  //这个对象持久  所以是左值
int &r3 = r1;  //  r1是一个持久的对象  所以是左值
int &&r4 = vi[0] * f();  //  vi[0] * f() 之后，这个整体变成了一个字面值常量  所以是右值
//最简单的判断方法，这个变量能不能自增自减。

//13.47看13.44的答案


int main()
{
    cout<<vi[0]<<endl;

    return 0;
}
