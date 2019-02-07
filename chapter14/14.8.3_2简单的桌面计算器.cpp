#include <iostream>
#include <map>
#include <functional>
using namespace std;
/*
    可调用对象分别对其参数执行了不同的算符运算，尽管他们的类型各部相同，但是可以共享同一种调用形式 int(int,int)
    使用map将表示符号的string对象作为关键字，使用实现运算符的函数作为值。
*/
//不同类型可能具有相同的调用形式
//普通函数
int add(int i,int j){return i+j;}
//lambda,其产生一个未命名的函数对象类
auto mod = [](int i,int j){return i % j;};
/*
    lambda有它自己的类类型， 该类型与存储在binops中的值的类型不匹配
    可以用一个名为function的新标准库类型解决上述问题，function定义在functional头文件中

    function是一个模板，和我们使用过的其他模板一样，当创建一个具体的function类型时我们必须提供额外的信息。
    在此例中，额外信息是指该function类型能够表示的对象的调用形式。
*/
//函数对象类
struct divide
{
    int operator()(int denominator,int divisor){
        return denominator / divisor;
    }
};

function<int(int,int)> f1 = add;
function<int(int,int)> f2 = divide();  //构造一个divide的临时对象
function<int(int,int)> f3 = [](int i,int j){ return i * j; };



int main()
{
    cout<<f1(4,2)<<endl;
    cout<<f2(4,2)<<endl;
    cout<<f3(4,2)<<endl;
//    //构建从运算符到函数指针的映射关系，其中函数接受2个int返回一个int
//    map<string,int(*)(int,int)> binops;
//    //将add的指针添加到binops中。
//    binops.insert({"+",add});  //{"+",add}是一个pair
//用function模板重新定义map
    map<string,function<int(int,int)>> binops = {
        { "+",add },                                //函数指针
        { "-",std::minus<int>() },                  //标准库函数对象
        { "/",divide() },                           //用户定义的函数对象
        { "*",[](int i,int j){return i*j;} },       //未命名的lambda
        { "%",mod },                                //命名了的lambda对象
    };

    cout<<binops["+"](10,5)<<endl;  //调用add(10,5)
    cout<<binops["-"](10,5)<<endl;  //使用minus<int>对象的调用运算符
    cout<<binops["/"](10,5)<<endl;  //使用divide对象的调用运算符
    cout<<binops["*"](10,5)<<endl;  //调用lambda对象
    cout<<binops["%"](10,5)<<endl;  //调用lambda函数对象


    return 0;
}
