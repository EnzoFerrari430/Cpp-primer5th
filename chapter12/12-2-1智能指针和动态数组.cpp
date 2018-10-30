#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

/*
    ��׼���ṩ��һ�����Թ���new����������unique_ptr�汾
    Ϊ��ʹ��unique_ptr����̬���飬���Ǳ����ڶ������ͺ����һ�Կ�����

    ע�⣡���� ��һ��unique_ptrָ��һ������ʱ�����ǲ���ʹ�õ�ͼ�ͷ��Ա�����
    ��Ϊunique_ptrָ�����һ����������ǵ������������Щ�������������ġ�
    ���⣬��һ��unique_ptrָ��һ������ʱ������ʹ���±�����������������е�Ԫ��

    shared_ptr ��ֱ��֧�ֹ���̬���顣���ϣ��ʹ��shared_ptr����һ����̬���飬�����ṩ�Լ������ɾ����
*/

int main()
{
    unique_ptr<int[]> up(new int[10]);
    for(size_t i = 0; i != 10; ++i)
    {
        up[i] = i;
    }
    for(size_t i = 0; i != 10; ++i)
    {
        cout<<up[i]<<" ";
    }
    cout<<endl;

    up.release();  //�Զ�ʹ��delete[] ������ָ��


    //Ϊ��ʹ��shared_ptr�������ṩһ��ɾ����
    shared_ptr<int> sp(new int[10],[](int *p)
    {
        delete[] p;
    });
    for(size_t i = 0; i != 10; ++i)
    {
        //shared_ptrδ�����±������
        //sp[i] = i;
        //ʹ��get��ȡһ������ָ��
        *(sp.get() + i) = i;
    }
    for(size_t i = 0; i != 10; ++i)
    {
        cout<<*(sp.get()+i)<<" ";
    }
    cout<<endl;
    sp.reset();


    return 0;
}
