#include <iostream>
using namespace std;
/*
    可以通过将拷贝控制成员定义为=default来显示要求编译器生成合成的版本

    当在类内用=default修饰成员声明时，合成的函数将隐式地声明为内联的。
    如果不希望合成的成员是内联函数，应该只对类外定义使用=default
*/

class Sales_data
{
    //拷贝控制成员
    Sales_data() = default;
    Sales_data(const Sales_data &) = default;
    Sales_data& operator=(const Sales_data &);
    ~Sales_data() = default;
    //其他成员定义如前
};

Sales_data& Sales_data::operator=(const Sales_data&) = default;

int main()
{
    cout<<"hello world"<<endl;
    return 0;
}
