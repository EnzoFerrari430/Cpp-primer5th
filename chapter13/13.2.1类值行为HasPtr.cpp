#include <iostream>
#include <string>

using namespace std;
//�඼�����Լ����ڴ�ռ�
class HasPtr
{
public:
    HasPtr(const string &s = string() ):ps(new string(s)),i(0){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}

    HasPtr& operator=(const HasPtr&);
    ~HasPtr(){delete ps;}
private:
    string *ps;
    int i;
};

HasPtr& operator=(const HasPtr& rhs)
{
    auto newp = new string(*rhs.ps);
    delete ps;  //���ͷ�ԭ���ǿ��ڴ�,�м��м�,
    //������rhs��*this��ͬһ���������Ǿͽ������ͷŵ��ڴ��п������ݡ�����Ҫ�ȿ�������ʱ������ȥ
    ps = newp;  //���Ҳ�������󿽱����ݵ�������
    i = rhs.i;
    return *this;
}

int main()
{



    return 0;
}
