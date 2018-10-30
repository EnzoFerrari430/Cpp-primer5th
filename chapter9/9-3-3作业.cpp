#include <iostream>
#include <vector>
#include <list>
using namespace std;
//9.25 elem1和elem2相等 就删除该迭代器表示的元素  elem2是尾后迭代器  就删除elem1开始到最后的全部元素  elem1和elem2都是尾后迭代器就不删除元素
//9.26
int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};
    int length = sizeof(ia)/sizeof(int);
    vector<int> vi;
    list<int> li;
    for(int i = 0;i<length;++i)
    {
        vi.emplace_back(ia[i]);
        li.emplace_back(ia[i]);
    }
    for(auto c = vi.begin();c != vi.end();)
    {
        if(!(*c % 2))
        {
            c = vi.erase(c);
        }
        else
        {
            ++c;
        }
    }
    for(auto c = li.begin();c != li.end();)
    {
        if(*c % 2)
        {
            c = li.erase(c);
        }
        else
        {
            ++c;
        }
    }

    for(auto c: vi)
        cout<<c<<' ';
    cout<<endl;
    for(auto c: li)
        cout<<c<<' ';
    cout<<endl;
    return 0;
}
