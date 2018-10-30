#include <iostream>
using namespace std;
/*
    如果同一作用域内的几个函数名字相同但形参列表不同，我们称之为重载函数
*/
void print(const char *cp);
void print(const int *beg,const int *end);
void print(const int ia[],size_t size);
//这些函数接收的形参不一样，调用这些函数的时候，编译器根据传递的实参类型推断想要调用的是哪个函数

//★如果2个函数的形参列表一样，但是他们的返回类型不一样，这样是不被允许的，第二个函数将会报错
//有的时候2个形参列表看起来不一样但是实际上是相同的，这样函数声明不会出错，但是函数定义会出错

void lookup(const int &r);
void lookup(const int &i);
void lookup(const int &);

//同理 变量也可以多次声明
extern int i;
extern int i;

//顶层const不影响传入函数的对象。一个拥有顶层const的形参无法和没有顶层const的形参区分开来
void loop(const int);
void loop(int);
//第二个声明和第一个是等价的

//如果形参是某种类型的指针或引用，则通过区分其指向的是常量对象还是非常量对象可以实现函数重载，此时const是底层的
void read(int *);
void read(const int *);
//这是2个函数，编译器可以通过实参是否是常量来推断应该调用哪个函数。因为const不能转换成其他类型。我们只能把const对象传递给const形参
//相反，非常量可以转换成const,所以上面的函数都能作用于非常量对象或者指向非常量对象的指针
//后面将介绍，当传递一个非常量对象或者指向非常量对象的指针时，编译器会优化选用非常量版本

int main()
{



    return 0;
}
