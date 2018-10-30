#include <iostream>
#include <memory>
using namespace std;


//��ֵ����
void process(shared_ptr<int> p)
{
    cout<<"inside the process function: "<<p.use_count()<<"\n";
}

int main()
{
    auto p = new int();
    auto sp = make_shared<int>();

    process(sp);    //�Ϸ�
    //process(new int());   ���Ϸ�,���ܽ�����ָ��ת��������ָ��
    //process(p);   ���Ϸ�,���ܽ�����ָ��ת��������ָ��
    process(shared_ptr<int>(p));  //�Ϸ� ����Σ��

    //cout<<*sp<<endl;

    return 0;
}
