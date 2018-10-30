#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
    9.3
        两个迭代器begin和end必须指向同一个容器中的元素，或者是容器最后一个元素之后的位置；
        而且，对begin反复进行递增操作，可以保证达到end，即end不在begin之前。


    9.6
        不能用<符号 运算符<在std :: list中未实现，因为std :: list基本上是双向链表。 链表节点的地址不一定是连续的。

*/
//9.4,9.5
int main()
{
    vector<int> ival{0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int num;
    cin>>num;
    vector<int>::iterator vi;
    for(vi = ival.begin();vi != ival.end(); ++vi)
    {
        if(*vi == num)
        {
            cout<<"find pos:"<<vi - ival.begin()<<endl;
            return 0;
        }
    }
    cout<<"cant find pos"<<endl;

    return 0;
}





