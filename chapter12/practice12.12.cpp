#include <iostream>
#include <memory>
using namespace std;


//赋值传参
void process(shared_ptr<int> p)
{
    cout<<"inside the process function: "<<p.use_count()<<"\n";
}

int main()
{
    auto p = new int();
    auto sp = make_shared<int>();

    process(sp);    //合法
    //process(new int());   不合法,不能将内置指针转换成智能指针
    //process(p);   不合法,不能将内置指针转换成智能指针
    process(shared_ptr<int>(p));  //合法 但是危险

    //cout<<*sp<<endl;

    return 0;
}
