#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <list>
using namespace std;
/*
    向目标位置的迭代器指向的输出序列中的元素写入数据。
    此算法接受3个迭代器，前2个表示一个输入范围，第3个表示目的序列的启示位置
    copy返回的是目的位置迭代器（递增后）的值

    ★此算法将输入范围中的元素拷贝到目的序列中，传递给拷贝的目的序列至少要包含与输入序列一样的多的元素。


    很多算法都提供了拷贝版本，这些算法计算新元素的值，但不会将它们放置在输入序列的末尾，而是创建一个新序列保存这些值
*/
int main()
{
    //内置数组的拷贝
    int a1[] = {0,1,2,3,4,5,6,7,8,9};  //这种写法一定要初始化
    int a2[sizeof(a1)/sizeof(*a1)];  //a2 a1大小一样
    //ret指向拷贝到a2的尾元素之后的位置
    auto ret = copy(begin(a1),end(a1),a2);
    for(auto c: a2)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    /*
    list<int> ilst{4,0,0,8,6,9,9,8,7,8};
    replace(ilst.begin(),ilst.end(),0,42);
    for(auto c: ilst)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    */

    //如果我们希望保留原序列不变，可以调用replace_copy，此算法接受额外第3个参数，指出调整后序列的保存位置
    list<int> ilst{4,0,0,8,6,9,9,8,7,8};
    list<int> ivec;
    replace_copy(ilst.begin(),ilst.end(),back_inserter(ivec),0,42);  //原来的不变，ivec为ilst的拷贝，替换了0
    for(auto c: ivec)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    for(auto c: ilst)
    {
        cout<<c<<' ';
    }
    cout<<endl;





    return 0;
}
