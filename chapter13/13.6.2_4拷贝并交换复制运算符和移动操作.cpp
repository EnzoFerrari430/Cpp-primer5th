#include <iostream>
#include <string>

using namespace std;
//�඼�����Լ����ڴ�ռ�
class HasPtr
{

    friend void swap(HasPtr&,HasPtr&);
public:
    HasPtr(const string &s = string() ):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &p);

    //����ƶ����캯��
    HasPtr(HasPtr &&p) noexcept:ps(p.ps),i(p.i){p.ps = 0;cout<<"move construct"<<endl;}  //���������HasPtr��ָ����Ϊ0���Ӷ�ȷ�������ƺ�Դ�����ǰ�ȫ�ġ����Ըú��������׳��쳣�����Ϊnoexpect
    //��ֵ����������ƶ���ֵ�������Ҳ�ǿ�����ֵ�������������ʵ�ε���������
    /*
        ���������һ�������ò���������ζ�Ŵ˲���Ҫ���п�����ʼ���������������ʼ��Ҫ����ʵ�����͡�
        ������ʼ��Ҫôʹ�ÿ������캯����Ҫôʹ���ƶ����캯��--��ֵ����������ֵ���ƶ���
        ��˵�һ�ĵ��������ʵ���˿�����ֵ��������ƶ���ֵ�����2�ֹ���
    */
    HasPtr & operator=(HasPtr &&rhs)noexcept;

    //���������ֵ������Ͳ���Ҫ��
    HasPtr& operator=(const HasPtr&);
    ~HasPtr(){delete ps;}
private:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;  //���ͷ�ԭ���ǿ��ڴ�,�м��м�,
    //������rhs��*this��ͬһ���������Ǿͽ������ͷŵ��ڴ��п������ݡ�����Ҫ�ȿ�������ʱ������ȥ
    ps = newp;  //���Ҳ�������󿽱����ݵ�������
    i = rhs.i;
    cout<<"copy assignment"<<endl;
    return *this;
}

HasPtr& HasPtr::operator=(HasPtr &&rhs)noexcept
{
    delete ps;
    ps = rhs.ps;
    i = rhs.i;
    rhs.ps = nullptr;
    cout<<"move assignment"<<endl;
    return *this;
}
inline void swap(HasPtr &lhs,HasPtr &rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps);
    swap(lhs.i,rhs.i);
}

int main()
{
    HasPtr hp,hp2;
    hp = hp2;  //hp2��һ����ֵ��hp2ͨ���������캯��������
    //�������캯������һ���µ�string��������hp2ָ���string


    hp = std::move(hp2);  //�ƶ����캯���ƶ�hp2
    //std::move��һ����ֵ�󶨵�hp2�ϡ�������¿������캯�����ƶ����캯�����ǿ��еġ�����ʵ����һ����ֵ���ã��ƶ����캯���Ǿ�ȷƥ�䡣
    //�ƶ����캯����hp2����ָ�룬����������ڴ档





    return 0;
}
