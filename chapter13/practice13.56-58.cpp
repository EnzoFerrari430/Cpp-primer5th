#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
    ���ǿ���ͨ���ڲ����б�����һ�������޶�����ָ����ǰ�������thisָ���Ķ��󣩵���ֵ����ֵ�޶�

    �޶��������� & �� &&���ֱ�ָ��this����ָ��һ����ֵ��������ֵ��
    ����const�޶����������޶���ֻ�����ڣ���static����Ա����,!!!�ұ���ͬʱ�����ں����������Ͷ�����
*/
class Foo
{
public:
    Foo();
    Foo &operator=(const Foo&) &;  //ֻ������޸ĵ���ֵ��ֵ

    //һ����������ͬʱ��const�������޶����ڴ�����£������޶������������const�޶���֮��

    //Foo someMem() & const;  //����const�޶���������ǰ
    Foo anotherMem() const &;  //��ȷ��const�޶�����ǰ

    //һ����Ա�������Ը����Ƿ���const���������ذ汾
    Foo &fun(int a);
    const Foo &fun(int a)const ;

    //������������أ������޶���Ҳ�����������ذ汾�����һ������ۺ������޶�����const������һ����Ա���������ذ汾
    Foo sorted() &&;  //�����ڿɸı����ֵ
    Foo sorted() const &;  //�������κ����͵�Foo

    //������const��Ա����ʱ�����Զ���2���汾��Ψһ�Ĳ�����һ���汾��const�޶�����һ��û�С�
    //  ���������������޶��ĺ�����һ�����������2�������ϰ汾��ͬ������ͬ�����б�ĳ�Ա�������ͱ�������к��������������޶���,���߶�����

//    Foo ffun() &&;
//    Foo ffun() const;  ���󣬱�����������޶���

private:
    vector<int> data;

};

//�ð汾��һ����ֵ�����Ըı䣬��˿���ԭַ����
Foo Foo::sorted() &&
{
    cout<<"move sorted"<<endl;
    sort(data.begin(),data.end());
    return *this;
}

//�ð汾�Ķ�����const������һ����ֵ��������������ܶ������ԭַ����Ϊʲô���ܶ���ֵ����ԭַ����
Foo Foo::sorted() const &
{
    cout<<"copy sorted1"<<endl;
    Foo ret(*this);     //����һ������
    sort(ret.data.begin(),ret.data.end());  //���򸱱�
    return ret;  //���ظ���
}

//13.56
// �Լ��𰸣�����Foo ret(*this)  ��һ���������캯��  ������һ����ֵret ��ֵret.sorted�ֵ��ûظú���������ѭ����ջ���
Foo Foo::sorted() const &
{
    cout<<"copy sorted2"<<endl;
    Foo ret(*this);
    return ret.sorted();
}

//13.57
//  �Լ��𰸣��о����������ͬ��Ҳ������ѭ����ջ���
//��׼��  ��������ȷ�ģ�  ����������ΪFoo(*this)��һ��������������ֵ  ��������sortedƥ�䵽��ֵ���ð汾
Foo Foo::sorted() const &
{
    return Foo(*this).sorted();
}

Foo& Foo::operator=(const Foo &rhs) &
{
    //ִ�п�������
    return *this;
}

int main()
{
    //ͨ��������һ�������ϵ��ó�Ա�����������ܸö�����һ����ֵ������ֵ
    string s1 = "a value",s2 = "another";
    auto n = (s1 + s2).find('a');
    cout<<n<<endl;
    cout<<s1 <<" "<<s2<<endl;
    s1 + s2 = "wow";  //�˴���2��string�����ӽ��--һ����ֵ�������˸�ֵ��
    //�ھɱ�׼�У�����û�а취��ֹ����ʹ�÷�ʽ��Ϊ��ά�����ļ����ԣ��±�׼����Ȼ�������Ҹ�ֵ��
    //��������ϣ��ǿ����������������һ����ֵ


    return 0;
}
