#include <iostream>
#include <vector>
using namespace std;
/*
    for�����﷨
    for(init-statement;condition;expression)
        statement
    init-statement��3����ʽ ������䣬���ʽ�����߿����
    һ������£�init-statementֻ��ʼ��һ��ֵ�����ֵ����ѭ���Ľ��ж��ı�
    conditionΪѭ��������Ϊ���ִ��һ��ѭ��
    expression�����޸�init-statement��ʼ���ı���


    ���ʡ��condition����Ч���ȼ�������������д��һ��true������Ҫ��ѭ����������为���˳�ѭ�������������ֹ��ѭ����ȥ

*/
int main()
{
    //for���ͷ�Ķ��ض���
    vector<int> vi;
    int i,num,sz;
    while(cin>>num)
    {
        vi.push_back(num);
    }
    //for���ͷ�Ķ��ض���,��vectorԪ�ؿ���һ����ӵ�ԭ��Ԫ�صĺ���
    for(i = 0,sz = vi.size() ; i != sz; ++i)
    {
        vi.push_back(vi[i]);
    }

    for(i = 0; i< vi.size() ;++i)
    {
        cout<<vi[i]<<' ';
    }


    return 0;
}
