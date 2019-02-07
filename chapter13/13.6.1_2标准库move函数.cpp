#include <iostream>
#include <utility>  //新标准库move函数所在的头文件
using namespace std;
/*
    我们可以通过调用一个名为move的新标准库函数来获得绑定到左值上的右值引用
*/
int main()
{
    int rr1 = 42;
    int &&rr3 = std::move(rr1);  //rr1是左值,通过move函数绑定到右值引用上
    //这样使用之后，除了对rr1赋值或者销毁之外，不再使用它。
    //在调用move之后，不能对  移后 源对象  的值做任何假设

    // !!!  move函数要直接调用  std::move  而不是move。后面会解释原因

    return 0;
}
