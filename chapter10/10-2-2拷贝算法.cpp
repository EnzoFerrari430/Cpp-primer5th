#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>
#include <list>
using namespace std;
/*
    ��Ŀ��λ�õĵ�����ָ�����������е�Ԫ��д�����ݡ�
    ���㷨����3����������ǰ2����ʾһ�����뷶Χ����3����ʾĿ�����е���ʾλ��
    copy���ص���Ŀ��λ�õ������������󣩵�ֵ

    ����㷨�����뷶Χ�е�Ԫ�ؿ�����Ŀ�������У����ݸ�������Ŀ����������Ҫ��������������һ���Ķ��Ԫ�ء�


    �ܶ��㷨���ṩ�˿����汾����Щ�㷨������Ԫ�ص�ֵ�������Ὣ���Ƿ������������е�ĩβ�����Ǵ���һ�������б�����Щֵ
*/
int main()
{
    //��������Ŀ���
    int a1[] = {0,1,2,3,4,5,6,7,8,9};  //����д��һ��Ҫ��ʼ��
    int a2[sizeof(a1)/sizeof(*a1)];  //a2 a1��Сһ��
    //retָ�򿽱���a2��βԪ��֮���λ��
    auto ret = copy(begin(a1),end(a1),a2);
    for(auto c: a2)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    /*
    list<int> ilst{4,0,0,8,6,9,9,8,7,8};
    replace(ilst.begin(),ilst.end(),0,42);
    for(auto c: ilst)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    */

    //�������ϣ������ԭ���в��䣬���Ե���replace_copy�����㷨���ܶ����3��������ָ�����������еı���λ��
    list<int> ilst{4,0,0,8,6,9,9,8,7,8};
    list<int> ivec;
    replace_copy(ilst.begin(),ilst.end(),back_inserter(ivec),0,42);  //ԭ���Ĳ��䣬ivecΪilst�Ŀ������滻��0
    for(auto c: ivec)
    {
        cout<<c<<' ';
    }
    cout<<endl;
    for(auto c: ilst)
    {
        cout<<c<<' ';
    }
    cout<<endl;





    return 0;
}
