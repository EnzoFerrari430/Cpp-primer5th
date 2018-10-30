#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

/*
    任何具有输出运算符的类型都可以定义ostream_iterator。
    当创建一个ostream_iterator时，我们可以提供(可选的)第二参数，它必须是C风格是字符串
    不允许空或者尾后位置的ostream_iterator

ostream_iterator操作
    ostream_iterator<T> out(os)     将类型为T的值写入到输出流os中
    ostream_iterator<T> out(os,d)   ............................，每个值后面都输出一个d

    out = val;      用<<运算符将val写入到out所绑定的ostream中。val的类型必须与out可写的类型兼容

    *out, ++out, out++  这些运算符是存在的，但是不对out做任何事情。每个运算符都返回out
*/

int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    ostream_iterator<int> out_iter(cout," ");
    for(auto e : vec)
    {
        //*out_iter++ = e;  //向out_iter赋值时，可以忽略解引用和递增运算
        out_iter = e;
    }
    cout<<endl;

    //可以通过copy来打印vec中的元素.  vec迭代器拷贝给输出流迭代器
    copy(vec.begin(),vec.end(),out_iter);
    cout<<endl;
    return 0;
}
