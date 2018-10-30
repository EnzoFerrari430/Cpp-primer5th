#include <iostream>
#include <forward_list>
using namespace std;
/*
    ��Ϊforward_list�ǵ�������,��ɾ��һ��Ԫ��ʱ�����ǲ����ҵ������ɾ��Ԫ�ص���һ��Ԫ�أ��Ա�����һ��Ԫ��ָ��ɾԪ�ص���һ��Ԫ��
    ����forward_list��ӻ�ɾ��Ԫ�صĲ�����ͨ���ı����Ԫ��֮���Ԫ������ɵġ�
    forward_listδ����insert emplace erase ����������Ϊinsert_after emplace_after erase_after.
    Ϊ��֧������Ԫ��֮ǰ��ӻ�ɾ��forward_listҲ������before_begin

��forward_list�в����ɾ��Ԫ�صĲ���
    lst.before_begin()      ����ָ��������Ԫ��֮ǰ�����ڵ�Ԫ�صĵ��������˵��������ܽ����á�cbefore_begin()����const_iterator
    lst.cbefore_begin()

    lst.insert_after(p,t)   �ڵ�����p֮���λ�ò���Ԫ�ء�t��һ������n��������b��e�Ǳ�ʾ��Χ��һ�Ե�������b��e����ָ��lst�ڲ���
    lst.insert_after(p,n,t) il��һ���������б�����һ��ָ�����һ������Ԫ�صĵ������������ΧΪ�գ��򷵻�p��
    lst.insert_after(p,b,e) ��pΪβ���������������Ϊδ����
    lst.insert_after(p,il)

    emplace_after(p,args)   ʹ��args��pָ����λ��֮�󴴽�һ��Ԫ�ء�����һ��ָ�������Ԫ�صĵ���������p��β���������������Ϊδ����

    lst.erase_after(p)      ɾ��pָ��֮���Ԫ�أ���ɾ����b֮��ֱ����������e��֮ǰ��Ԫ�ء�����һ��ָ��ɾԪ��֮��ĵ���������������
    lst.erase_after(b,e)    ������Ԫ�أ��򷵻�β������������pָ��lst��βԪ�ػ�����һ��β���������������Ϊδ����

    ��forward_list����ӻ�ɾ��Ԫ��ʱ�����Ǳ����ע2����������һ��ָ������Ҫ�����Ԫ�أ���һ��ָ����ǰ����
*/
int main()
{
    forward_list<int> flst = {0,1,2,3,4,5,6,7,8,9};
    auto prev = flst.before_begin();  //��ʾflst����ǰԪ��
    auto curr = flst.begin();         //��ʾflst�ĵ�һ��Ԫ��
    while(curr != flst.end())
    {
        if( *curr % 2)
            curr = flst.erase_after(prev);  //ɾ��prevָ��֮���Ԫ�أ�����һ��ָ��ɾԪ��֮��ĵ�����
        else
        {
            prev = curr;
            ++curr;
        }
    }
    for(auto c:flst)
        cout<<c<<' ';
    cout<<endl;

    return 0;
}
