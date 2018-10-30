#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;
/*
˳��������ɾ������
    ��Щ������ı������Ĵ�С�����Բ��ʺ�array
    forward_list������汾��erase
    forward_list��֧��pop_back��vector��string��֧��pop_front

    c.pop_back()        ɾ��c�е�βԪ�ء���cΪ�գ�������Ϊδ���塣��������void
    c.pop_front()       ɾ��c�е���Ԫ�ء���cΪ�գ�������Ϊδ���塣��������void
    c.erase(p)          ɾ��������p��ָ����Ԫ�أ�����һ��ָ��ɾԪ��֮��Ԫ�صĵ���������pָ��βԪ�أ��򷵻�β�����������p��
                        β���������������Ϊδ����
    c.erase(b,e)        ɾ��������b��e��ָ�������ڵ�Ԫ�ء�����һ��ָ�����һ����ɾԪ��֮��Ԫ�صĵ���������e�������β���������
                        ����Ҳ����β���������
    c.clear()           ɾ��c�е�����Ԫ�أ�����void
*/
int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    vi.erase(vi.begin(),vi.end());
    for(auto c: vi)
        cout<<c<<' ';
    cout<<endl;


    return 0;
}
