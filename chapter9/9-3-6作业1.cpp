#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;
//list�汾
int main()
{
//ѭ��ɾ��żԪ�أ�������Ԫ��
    list<int> vi = {0,1,2,3,4,5,6,7,8,9};
    auto iter = vi.begin();
    while(iter != vi.end())
    {
        if(*iter % 2)
        {
            iter = vi.insert(iter,*iter);  //��iterλ��֮ǰ����һ��*iter �����µ�Ԫ�صĵ�����
            //iter += 2;  //����֧������洢  ��advice
            advance(iter,2);
        }
        else
        {
            iter = vi.erase(iter);  //iterָ��ɾ��Ԫ�صĺ�һ��Ԫ��
        }
    }

    for(auto c: vi)
        cout<<c<<' ';
    cout<<endl;
    return 0;
}
