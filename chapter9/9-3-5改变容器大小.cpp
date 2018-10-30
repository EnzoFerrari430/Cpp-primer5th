#include <iostream>
#include <list>
using namespace std;
/*
    我们可以用resize来增大或缩小容器，与往常一样array不支持resize。
    如果当前大小大于所要求的大小，容器后部的元素会被删除
    如果当前大小小于新的大小，会将新元素添加到容器的后部


c.resize(n)     调整c为大小为n个元素，若n小于本身大小就删除后面元素，大于就在后面添加默认值
c.resize(n,t)   调整c为大小为n个元素，若n小于本身大小就删除后面元素，大于就在后面添加值为t的元素
*/
int main()
{
    list<int> ilist(10,42);  //10个42
    ilist.resize(15);  //将5个值为0的元素添加到ilist的末尾
    for(auto c: ilist)
        cout<<c<<' ';
    cout<<endl;
    ilist.resize(25,-1);  //将10个值为-1的元素添加到ilist的末尾
    for(auto c: ilist)
        cout<<c<<' ';
    cout<<endl;
    ilist.resize(5);    //将后面20个元素删除
    for(auto c: ilist)
        cout<<c<<' ';
    cout<<endl;

    return 0;
}
