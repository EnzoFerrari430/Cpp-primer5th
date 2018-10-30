#include <iostream>
#include <typeinfo>
using namespace std;

/*
    设置一个类型为auto的引用时，初始值中的顶层常量属性仍然保留。
    和往常一样，如果我们给初始值绑定一个引用，则此时的常量就不是顶层常量了

*/
int main()
{
    /*
    const int i = 42,&r = i;
    auto num = r;
    cout<<typeid(r).name()<<endl;
    cout<<typeid(num).name()<<endl;
    */
    int i = 0,&r = i;
    const int ci = i;
    auto k = ci,&l = i;  //k是int l是int的引用
    auto &m = ci,*p = &ci;
    //auto &n = i,*p2 = &ci;  i是int p2是pki
    cout<<typeid(m).name()<<endl;  //i
    cout<<typeid(p).name()<<endl;  //pki
    cout<<typeid(*p).name()<<endl;  //i
    cout<<typeid(p2).name()<<endl;  //pki
    cout<<typeid(*p2).name()<<endl;  //i
    cout<<typeid(&ci).name()<<endl;  //pki



    return 0;
}
