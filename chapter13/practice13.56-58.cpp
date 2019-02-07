#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    我们可以通过在参数列表后放置一个引用限定符来指出当前运算对象（this指出的对象）的左值或右值限定

    限定符可以是 & 或 &&，分别指出this可以指向一个左值或者是右值。
    类似const限定符，引用限定符只能用于（非static）成员函数,!!!且必须同时出现在函数的声明和定义中
*/
class Foo
{
public:
    Foo();
    Foo &operator=(const Foo&) &;  //只能向可修改的左值赋值

    //一个函数可以同时用const和引用限定。在此情况下，引用限定符必须跟随在const限定符之后

    //Foo someMem() & const;  //错误：const限定符必须在前
    Foo anotherMem() const &;  //正确：const限定符在前

    //一个成员函数可以根据是否有const来区分重载版本
    Foo &fun(int a);
    const Foo &fun(int a)const ;

    //类似上面的重载，引用限定符也可以区分重载版本，而且还可以综合引用限定符和const来区分一个成员函数的重载版本
    Foo sorted() &&;  //可用于可改变的右值
    Foo sorted() const &;  //可用于任何类型的Foo

    //当定义const成员函数时，可以定义2个版本，唯一的差别就是一个版本有const限定，另一个没有。
    //  ！！！！！引用限定的函数则不一样，如果定义2个或以上版本的同名和相同参数列表的成员函数，就必须对所有函数都加上引用限定符,或者都不加

//    Foo ffun() &&;
//    Foo ffun() const;  错误，必须加上引用限定符

private:
    vector<int> data;

};

//该版本是一个右值，可以改变，因此可以原址排序
Foo Foo::sorted() &&
{
    cout<<"move sorted"<<endl;
    sort(data.begin(),data.end());
    return *this;
}

//该版本的对象是const或者是一个左值，哪种情况都不能对其进行原址排序，为什么不能对左值进行原址排序
Foo Foo::sorted() const &
{
    cout<<"copy sorted1"<<endl;
    Foo ret(*this);     //拷贝一个副本
    sort(ret.data.begin(),ret.data.end());  //排序副本
    return ret;  //返回副本
}

//13.56
// 自己答案：这里Foo ret(*this)  是一个拷贝构造函数  构造了一个左值ret 左值ret.sorted又调用回该函数，无线循环，栈溢出
Foo Foo::sorted() const &
{
    cout<<"copy sorted2"<<endl;
    Foo ret(*this);
    return ret.sorted();
}

//13.57
//  自己答案：感觉这里和上面同理，也会无线循环，栈溢出
//标准答案  这里是正确的，  编译器会认为Foo(*this)是一个“无主”的右值  这里会调用sorted匹配到右值引用版本
Foo Foo::sorted() const &
{
    return Foo(*this).sorted();
}

Foo& Foo::operator=(const Foo &rhs) &
{
    //执行拷贝操作
    return *this;
}

int main()
{
    //通常我们在一个对象上调用成员函数，而不管该对象是一个左值还是右值
    string s1 = "a value",s2 = "another";
    auto n = (s1 + s2).find('a');
    cout<<n<<endl;
    cout<<s1 <<" "<<s2<<endl;
    s1 + s2 = "wow";  //此处对2个string的连接结果--一个右值，进行了赋值。
    //在旧标准中，我们没有办法阻止这种使用方式，为了维持向后的兼容性，新标准库仍然允许向右赋值。
    //但是我们希望强制左侧运算符对象是一个左值


    return 0;
}
