#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <iterator>  //定义了数组的begin 和end函数
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::begin;
using std::end;
int main()
{
    string nums[] = {"one","two","three"};
    string *p = &nums[0];

    //数组特性，很多用到数组名字的地方，编译器都会自动的将数组名字替换成一个指向数组首元素的指针
    string *p2 = nums;

    int ia[] = {0,1,2,3,4,5,6,7,8,9};
    auto ia2(ia);
    decltype(ia) ia3;
    //cout<<typeid(ia2).name()<<endl;  Pi整型指针  因为ia相当于 &ia[0]
    //cout<<typeid(ia3).name()<<endl;  A10_i  10个整数构成的数组

    //允许使用递增运算符将指向数组元素的指针向前移动到下一个位置上
    int *ptr = ia;
    ptr++;
    cout<<*ptr<<endl;

    //数组的迭代器使用，数组的首元素指针好得到，尾元素指针就指向尾元素的下一位置指针
    int *b = ia;  //首元素指针
    int *e = &ia[10];  //ia有10个元素，尾元素的索引是9，所以尾元素的下一位指针就是10
    for(b = ia;b!=e;b++)
    {
        cout<<*b<<" ";
    }
    cout<<endl;

    //虽然上面方法可以，但是要计算尾后指针，容易出错。C++11新标准引入2个名为begin和end的函数，这2个函数与容器中的函数
    //功能类似，但数组不是类类型，这2个函数不能当成员函数，只能把数组当做他们的参数
    int *beg = begin(ia);  //首元素指针
    int *last = end(ia);   //尾后指针




    return 0;
}
