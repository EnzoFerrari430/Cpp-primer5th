#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <ctime>
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::to_string;

class HasPtr
{
    friend void swap(HasPtr&,HasPtr&);
    friend bool operator<(const HasPtr& lhs,const HasPtr& rhs);  //��ò�����Ԫ��������ʽ
public:
    HasPtr(const string &s = string(),int n = 0 ):ps(new string(s)),i(n){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}

    HasPtr& operator=(const HasPtr&);
    //HasPtr& operator=(HasPtr rhs);
    //bool operator<(const HasPtr&) const;  //������ʹ�ó�Ա������ʽ
    ~HasPtr(){delete ps;}
public:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    cout<<"Reference Version"<<endl;
    auto newp = new string(*rhs.ps);
    delete ps;  //���ͷ�ԭ���ǿ��ڴ�,�м��м�,
    //������rhs��*this��ͬһ���������Ǿͽ������ͷŵ��ڴ��п������ݡ�����Ҫ�ȿ�������ʱ������ȥ
    ps = newp;  //���Ҳ�������󿽱����ݵ�������
    i = rhs.i;
    return *this;
}

//HasPtr& HasPtr::operator=(HasPtr rhs)  //�����������س�ͻ
//{
//    cout<<"normal Version"<<endl;
//    swap(*this,rhs);  //����汾���ÿ���rhs��thisָ��ָ����ǲ���ͬһ������
//    return *this;
//}

inline void swap(HasPtr& lhs,HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps);  //����ָ��
    swap(lhs.i,rhs.i);  //����int��Ա
}

bool HasPtr::operator<(const HasPtr &rhs) const
{
    return *ps < *rhs.ps;
}

bool operator<(const HasPtr& lhs,const HasPtr& rhs)
{
    return *lhs.ps < *rhs.ps;
}


int main()
{
    int i = 10;
    //string s = to_string(i);
    //cout<<s<<endl;
    srand(time(NULL));
    vector<HasPtr> vh;
    for(int i = 0 ; i < 10 ; ++i)
    {
        int a = rand()%100;
        vh.push_back(to_string(a));
    }

    sort(vh.begin(),vh.end());

    for(auto c: vh)
    {
        cout<<*c.ps<<" ";
    }
    cout<<endl;


    return 0;
}
