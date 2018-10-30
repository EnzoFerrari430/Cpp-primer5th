#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

struct Data
{
    int ival;
    string s;


};
//Specifies that a type is a literal type.
//Literal types are the types of constexpr variables and they can be constructed, manipulated, and returned from constexpr functions.

//指定类型是字面值类型。 字面值类型是constexpr变量的类型，它们可以被构造，操作和从constexpr函数返回。

//7.56不是，string不是字面值类型

int main()
{
    cout<<boolalpha;
    cout<<is_literal_type<Data>::value<<endl;  //测试是否可用作一种类型constexpr变量或可构造，请使用，或从返回constexpr函数。
    return 0;
}
