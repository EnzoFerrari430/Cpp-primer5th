#include <iostream>
#include <vector>
#include <list>
using namespace std;
//9.25 elem1��elem2��� ��ɾ���õ�������ʾ��Ԫ��  elem2��β�������  ��ɾ��elem1��ʼ������ȫ��Ԫ��  elem1��elem2����β��������Ͳ�ɾ��Ԫ��
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
