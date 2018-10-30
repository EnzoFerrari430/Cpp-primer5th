#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
/*
��Щ������ı������Ĵ�С��array��֧����Щ����
forward_list���Լ�ר�Ű汾��insert��emplace
forward_list��֧��push_back��emplace_back
vector��string��֧��push_front��emplace_front

c.push_back(t)          ��c��β������һ��ֵΪt����args������Ԫ�ء�����void
c.emplace_back(args)

c.push_front(t)
c.emplace_front(args)   ��c��ͷ������һ��ֵΪt����args������Ԫ�ء�����void

c.insert(p,t)
c.emplace(p,args)       �ڵ�����pָ���Ԫ��֮ǰ����һ��ֵΪt����args������Ԫ�ء�����ָ������ӵ�Ԫ�صĵ�����

c.insert(p,n,t)         �ڵ�����pָ���Ԫ��֮ǰ����n��ֵΪt��Ԫ�ء�����ָ������ӵĵ�һ��Ԫ�صĵ���������nΪ0���򷵻�p

c.insert(p,b,e)         ��������b��eָ�������ڵ�Ԫ�ز��뵽������pָ���Ԫ��֮ǰ��b��e����ָ��c�е�Ԫ�ء�����ָ������ӵĵ�һ��Ԫ�صĵ�����
                        ����ΧΪ�գ��򷵻�p

c.inert(p,il)           il��һ�������Ű�Χ��Ԫ��ֵ�б�����Щ����ֵ���뵽������pָ���Ԫ��֮ǰ������ָ������ӵĵ�һ��Ԫ�صĵ�����
                        ���б�Ϊ�գ��򷵻�p

��FBI warning:��һ��vector��string��deque����Ԫ�ػ�ʹ����ָ�������ĵ����������ú�ָ��ʧЧ


push_back ������array��forward_list֮�� ÿ��˳������������string����֧��push_back
push_front ��list��forward_list��deque����֧����Ϊpush_front
*/
int main()
{
    vector<int> vi{2,4,6,8,10};
    vi.emplace(vi.begin()+1,1301050224);
    for(auto c:vi)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    list<int> il;
    for(size_t ix = 0;ix!= 4;++ix)
    {
        il.push_front(ix);
    }
    for(auto c:il)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
