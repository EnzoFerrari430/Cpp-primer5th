#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;
/*
    �����п�����ֵ����ʱ��ÿ��shared_ptr�����¼�ж��ٸ�����shared_ptrָ����ͬ����

    ÿ��shared_ptr����һ�������ļ�������ͨ������Ϊ���ü��������ۺ�ʱ�����ǿ���һ��shared_ptr�����������������
    ����
        1.����һ��shared_ptr��ʼ����һ��shared_ptr
        2.������Ϊ�������ݸ�һ������
        3.��Ϊ�����ķ���ֵ
    �������ݼ�
    ����
        1.��shared_ptr����һ����ֵ
        2.shared_ptr�����٣��ֲ�shared_ptr�뿪��������

    һ��һ��shared_ptr�ļ�������Ϊ0�����ͻ��Զ��ͷ��Լ�������Ķ���
*/
int main()
{
    auto q = make_shared<int>(222);
    auto r = make_shared<int>(42);
    r = q;  //��r��ֵ������ָ����һ����ַ
            //����qָ��Ķ�������ü���
            //�ݼ�rԭ��ָ��Ķ�������ü���
            //rԭ��ָ��Ķ�����û��������,���Զ��ͷ�

    vector<string> v1;
    {
        vector<string> v2 = {"a","an","the"};
        v1 = v2;
    }
    for(auto c : v1)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
