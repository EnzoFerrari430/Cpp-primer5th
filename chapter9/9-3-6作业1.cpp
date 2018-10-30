#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;
//list版本
int main()
{
//循环删除偶元素，复制奇元素
    list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if(*iter % 2)
        {
            iter = vi.insert(iter,*iter);  //在iter位置之前插入一个*iter 返回新的元素的迭代器
            //iter += 2;  //链表不支持随机存储  用advice
            advance(iter,2);
        }
        else
        {
            iter = vi.erase(iter);  //iter指向删除元素的后一个元素
        }
    }

    for(auto c: vi)
        cout<<c<<' ';
    cout<<endl;
    return 0;
}
