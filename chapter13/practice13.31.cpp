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
    friend bool operator<(const HasPtr& lhs,const HasPtr& rhs);  //最好采用友元的这种形式
public:
    HasPtr(const string &s = string(),int n = 0 ):ps(new string(s)),i(n){}
    HasPtr(const HasPtr &p):ps(new string(*p.ps)),i(p.i){}

    HasPtr& operator=(const HasPtr&);
    //HasPtr& operator=(HasPtr rhs);
    //bool operator<(const HasPtr&) const;  //不建议使用成员函数形式
    ~HasPtr(){delete ps;}
public:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    cout<<"Reference Version"<<endl;
    auto newp = new string(*rhs.ps);
    delete ps;  //先释放原先那块内存,切记切记,
    //★★如果rhs和*this是同一个对象，我们就将从已释放的内存中拷贝数据。所以要先拷贝到临时变量中去
    ps = newp;  //从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    return *this;
}

//HasPtr& HasPtr::operator=(HasPtr rhs)  //会和上面的重载冲突
//{
//    cout<<"normal Version"<<endl;
//    swap(*this,rhs);  //这个版本不用考虑rhs和this指针指向的是不是同一个对象
//    return *this;
//}

inline void swap(HasPtr& lhs,HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps,rhs.ps);  //交换指针
    swap(lhs.i,rhs.i);  //交换int成员
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
