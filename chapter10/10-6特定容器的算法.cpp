#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iterator>
using namespace std;
/*
    �������������Ԫ�أ�������Щ�㷨��������Ҫ����2��Ԫ�أ��Ͳ�����ͨ�õ��㷨������̫��
    ����汾���㷨���ܱȶ�Ӧͨ�ð汾�ĺõö�

    list��forward_list��Ա�����汾���㷨
    ��Щ��������Χvoid

    lst.merge(lst2)             ������lst2��Ԫ�غϲ���lst��lst��lst2�����������
    lst.merge(lst2,comp)        Ԫ�ؽ���lst2Ԫ��ɾ�����ںϲ�֮��lst2��Ϊ�ա���һ���汾ʹ��<��������ڶ����汾ʹ�ø����ıȽϲ���
    lst.remove(val)             ����eraseɾ���������ֵ���(==)
    lst.remove_if(pred)         ����һԪν��Ϊ���ÿ��Ԫ��
    lst.reverse()               ��תlst��Ԫ�ص�˳��
    lst.sort()                  ʹ��<������Ƚϲ�������Ԫ��
    lst.sort(comp)
    lst.unique()                ����eraseɾ��ͬһ��ֵ��������������һ���汾ʹ��==���ڶ����汾ʹ�ø����Ķ�Ԫν��
    lst.unique(pred)


    �������͵�splice�㷨
    lst.splice(args)��flst.splice_after(args)

    args:
        (p,lst2)        p��ָ��lst��Ԫ�صĵ�������ָ��flst��ǰλ�õĵ�����������lst2������Ԫ���ƶ���lst��p֮ǰ��λ�û�flst��pλ��֮��
                        ��λ�ã�Ȼ��Ԫ�ش�lst2��ɾ����lst2�����lst��flst������ͬ���Ҳ�����ͬһ������

        (p,lst2,p2)     p2��һ��ָ��lst2��λ����Ч�ĵ���������p2ָ���Ԫ���ƶ���lst�л��߽�p2֮���Ԫ���ƶ���flst��
                        lst2��������lst��flst��ͬ������

        (p,lst2,b,e)    b,e�����ʾlst2�еĺϷ���Χ,��������Χ�е�Ԫ�ش�lst2�ƶ���lst��flst
                        lst2��lst��flst��������ͬ��������p����ָ�������Χ��Ԫ��
*/
int main()
{


    return 0;
}
