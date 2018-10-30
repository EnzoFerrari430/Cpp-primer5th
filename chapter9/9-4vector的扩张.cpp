#include <iostream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
/*
容器大小的管理操作
    shrink_to_fit只适用于vector，string和deque
    capacity和reserve只适用于vector和string
    c.shrink_to_fit()   请将capacity()减少为与size()相同大小
    c.capacity()        不重新分配内存空间的话，c可以保存多少元素
    c.reserve(n)        分配至少能容纳n个元素的内存空间

    只有当需要的内存空间超过当前容量时，reserve调用才会改变vector的容量
    如果需求大小大于当前容量，reserve至少分配与需求一样大的内存空间
    如果需求大小小于或等于当前容量，reserve什么也不做。小于时容器不会退回内存空间
*/
int main()
{
    vector<int> ivec;
    cout<<"ivec:size: "<<ivec.size()<<" capacity: "<<ivec.capacity()<<endl;
    for(vector<int>::size_type ix = 0;ix != 24;++ix)
    {
        ivec.push_back(ix);
    }
    cout<<"ivec:size: "<<ivec.size()<<" capacity: "<<ivec.capacity()<<endl;
    ivec.reserve(50);
    cout<<"ivec:size: "<<ivec.size()<<" capacity: "<<ivec.capacity()<<endl;
    //调用shrink_to_fit要求vector将超出当前大小的多余内存退回系统
    ivec.shrink_to_fit();
    cout<<"ivec:size: "<<ivec.size()<<" capacity: "<<ivec.capacity()<<endl;
    //调用shrink_to_fit只是一个请求，标准库并不保证退还内存
    return 0;
}
