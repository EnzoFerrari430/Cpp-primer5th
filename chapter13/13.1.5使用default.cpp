#include <iostream>
using namespace std;
/*
    ����ͨ�����������Ƴ�Ա����Ϊ=default����ʾҪ����������ɺϳɵİ汾

    ����������=default���γ�Ա����ʱ���ϳɵĺ�������ʽ������Ϊ�����ġ�
    �����ϣ���ϳɵĳ�Ա������������Ӧ��ֻ�����ⶨ��ʹ��=default
*/

class Sales_data
{
    //�������Ƴ�Ա
    Sales_data() = default;
    Sales_data(const Sales_data &) = default;
    Sales_data& operator=(const Sales_data &);
    ~Sales_data() = default;
    //������Ա������ǰ
};

Sales_data& Sales_data::operator=(const Sales_data&) = default;

int main()
{
    cout<<"hello world"<<endl;
    return 0;
}
