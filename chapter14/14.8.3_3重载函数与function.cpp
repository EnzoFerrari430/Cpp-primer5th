#include <iostream>
#include <vector>
#include <functional>
#include <map>
using namespace std;

/*
    我们不能将重载函数的名字存入function类型的对象中
    直接存会不知道调用哪一个
*/

int add(int i,int j){return i + j;}
Sales_data add(const Sales_data &,const Sales_data &);
map<string ,function<int(int ,int)>> binops;
binops.insert({"+",add});  //错误，不知道调用哪个add

//解决上述问题可以使用一个函数指针
int (*fp)(int,int) = add;  //fp指针所指的add接受2个int版本
binops.insert({"+",fp});

//也能使用lambda来指定我们希望使用add版本
binops.insert({"+",[](int a,int b){ return add(a+b); }});


int main()
{


    return 0;
}
