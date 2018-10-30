#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    auto beg = vi.begin();
    while(beg != vi.end())
    {
        ++beg;
        //必须保证每次改变容器的操作之后都正确的重新定位迭代器.对vector、string和deque尤为重要
        beg = vi.insert(beg,42);  //在beg指向的元素之前创建一个值为t的元素，返回指向新添加元素的迭代器
        ++beg;
    }

    for(auto c: vi)
        cout<<c<<' ';
    cout<<endl;


    return 0;
}
