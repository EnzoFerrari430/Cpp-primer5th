#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;
//forward_list�汾
int main()
{
//ѭ��ɾ��żԪ�أ�������Ԫ��
    forward_list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    auto biter = vi.before_begin();
    while(iter != vi.end())
    {
        if(*iter % 2)
        {
            //0,1,2,3,4,5,6,7,8,9

            biter = vi.insert_after(biter,*iter);
            ++iter;
            ++biter;
        }
        else
        {
            iter = vi.erase_after(biter);
        }
    }

    for(auto c: vi)
        cout<<c<<' ';
    cout<<endl;
    return 0;
}


//9.32  �����������


