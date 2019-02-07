#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    如果类重载了函数调用符，则我们可以像使用函数一样使用该对象。因为这样的类同时也能存储状态，所以与普通函数相比他们更加灵活

    如果类定义了调用运算符，则该类的对象称作函数对象
*/

struct absInt
{
    int operator()(int val)const{
        return val < 0? -val : val;
    }
};

/*
    函数对象类出了operator()之外也可以包含其他成员
    这些成员一般被用于定制调用运算符中的操作
*/

class PrintString
{
public:
    PrintString(ostream &o = cout,char c = ' '):os(o),sep(c){}

    void operator()(const std::string &s) const {os<< s <<sep;}
private:
    ostream &os;  //用于写入的目的流
    char sep;  //用于将不同输出隔开的字符

};




int main()
{
    int i = -42;
    absInt absObj;
    int ui = absObj(i);
    cout<<ui<<endl;

    vector<string> vs = {"C","C++","java","python","go","ruby"};
    for_each(vs.begin(),vs.end(),PrintString(cerr,'\n'));



    return 0;
}
