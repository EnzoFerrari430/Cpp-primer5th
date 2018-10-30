#include <iostream>
#include <vector>
using namespace std;

//9.35 capacity：vector不重新分配内存的情况下 最多容纳的元素大小 size现在容纳元素的大小
//9.36 不可能。
//9.37 list是链表，是不需要预先获取一块内存的。 array是数组，定义的时候大小就已经确定了

//9.38
int main()
{
    int i;
    vector<int> vi;
    cout<<"vi size: "<<vi.size()<<"vi capacity: "<<vi.capacity()<<endl;
    while(cin>>i)
    {
        vi.emplace_back(i);
        cout<<"vi size: "<<vi.size()<<" vi capacity: "<<vi.capacity()<<endl;
    }


    return 0;
}

//9.39
