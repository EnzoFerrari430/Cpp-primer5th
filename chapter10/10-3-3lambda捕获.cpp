#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

/*
    与传值参数类似，采用值捕获的前提是变量可以拷贝。与参数不同的是，被捕获的变量的值是在lambda创建时拷贝，而不是调用时拷贝
*/

void fcn1()
{
    size_t v1 = 42;  //局部变量
    //将v1拷贝到名为f的可调用对象上
    auto f = [v1]{return v1;};
    v1 = 0;
    auto j = f();  //j = 42； f保存了我们创建它时v1的拷贝
    cout<<"f() "<<f()<<endl;
    cout<<"v1 "<<v1<<endl;
    cout<<"j "<<j<<endl;
}

//还可以采用引用的方式捕获变量
//一个以引用方式捕获的变量与其他任何类型的引用行为类似。当我们在lambda函数体内使用此变量时，实际上使用的是引用所绑定的对象
//引用捕获和返回引用有着相同的限制。如果我们采用引用方式捕获一个变量，就必须确保被引用的对象在lambda执行的时候是存在的
//尽量保持lambda的变量捕获简单化
void fcn2()
{
    size_t v1 = 42;  //局部变量
    //对象f2包含了v1的引用
    auto f2 = [&v1]{return v1;};
    v1 = 0;
    auto j = f2();  //j = 0; f2保存了v1的引用，而非拷贝
    cout<<"f2() "<<f2()<<endl;
    cout<<"v1 "<<v1<<endl;
    cout<<"j "<<j<<endl;


}


/*
隐式捕获
    除了显示列出要使用的变量之外，还可以让编译器根据lambda体中的代码来推断我们要使用哪些变量。 &告诉编译器采用引用的捕获方式
    =表示采用值捕获的方式

    //sz为隐式捕获，值捕获方式
    wc = find_if(words.begin(),words.end(),[=](const string &s){return s.size() >= sz;});
*/

//部分变量值捕获 剩余引用捕获
void biggiest(vector<string> &words,vector<string>::size_type sz,ostream &os = cout,char c = ' ')
{
    //os隐式捕获,引用捕获方式     c显式捕获，值捕获方式
    for_each(words.begin(),words.end(),[&,c](const string &s){os<<s<<c;});
    //os显式捕获,引用捕获方式     c隐式捕获，值捕获方式
    for_each(words.begin(),words.end(),[=,&os]{const string &s}{os<<s<<c;});
    //★使用混合使用隐式，显式捕获方式时，捕获列表的第一个元素必须是一个&或=。此符号指定了默认捕获方式为引用或值
    //★
}

int main()
{
    fcn1();
    fcn2();
    return 0;
}
