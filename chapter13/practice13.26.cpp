#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <stdexcept>
using namespace std;


class StrBlobPtr;

class student
{
public:
    vector<int> nGrades;
    string sName;
};

class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    friend class StrBlobPtr;
    StrBlobPtr begin() const;
    StrBlobPtr end() const;
public:
    StrBlob();
    StrBlob(initializer_list<string> il);
    StrBlob(const StrBlob &rhs);
    StrBlob& operator=(const StrBlob &rhs);

    size_type size() const
    {
        return data->size();   //通过类中的data成员实现
    }
    bool empty() const
    {
        return data->empty();   //const作用:  不修改成员变量
    }

    //添加和删除元素
    void push_back(const string &t)
    {
        data->push_back(t);
    }

    void pop_back();
    const void pop_back() const;

    //元素访问
    string& front();
    const string& front() const;

    string& back();
    const string& back() const;
private:
    shared_ptr<vector<string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i,const string &msg) const;
};
StrBlob::StrBlob():data(make_shared<vector<string>>()){}

StrBlob::StrBlob(initializer_list<string> il)
:data(make_shared<vector<string>>(il))
{

}

StrBlob::StrBlob(const StrBlob &rhs):data(make_shared<vector<string>>(*rhs.data)){}

StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
    data = make_shared<vector<string>>(*rhs.data);
    return *this;
}

void StrBlob::check(size_type i,const string &msg) const
{
    if( i >= data->size() )
    {
        throw out_of_range(msg);
    }
}

void StrBlob::pop_back()
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

const void StrBlob::pop_back() const
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}

string& StrBlob::front()
{
    check(0,"pop_back on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const
{
    check(0,"pop_back on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0,"pop_back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const
{
    check(0,"pop_back on empty StrBlob");
    return data->back();
}

class StrBlobPtr
{
    friend bool eq(const StrBlobPtr &lhs,const StrBlobPtr &rhs);
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(const StrBlob& a,size_t sz = 0):wptr(a.data),curr(sz){}

    //非常量引用不能绑定临时对象
    bool operator!=(const StrBlobPtr& p) const {
        return p.curr != curr;
    }

    string& deref() const{
        auto p = check(curr,"dereference past end");
        return (*p)[curr];
    }

    StrBlobPtr& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }


private:
    shared_ptr<vector<string>> check(size_t i,const string& msg) const{
        auto ret = wptr.lock();  //如果vector已经被销毁，则lock将返回一个空指针
        if( !ret )
            throw runtime_error("unbound StrBlobPtr");
        if( i >= ret->size() )
            throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

StrBlobPtr StrBlob::begin() const
{
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() const
{
    return StrBlobPtr(*this,data->size());  //尾后元素
}

int main()
{
    StrBlob b1;
    {
        StrBlob b2 = {"a","an","the"};
        b1 = b2;
        b2.push_back("about");
        cout<<"b2 size: "<<b2.size()<<endl;
        cout<<"b2 first element and last element is: "<<b2.front()<<" "<<b2.back()<<endl;
    }
    cout<<"b1 size: "<<b1.size()<<endl;
    cout<<"b1 first element and last element is: "<<b1.front()<<" "<<b1.back()<<endl;

    StrBlob b3 = b1;
    b3.push_back("next");
    cout<<"b3 size: "<<b3.size()<<endl;
    cout<<"b3 first element and last element is: "<<b3.front()<<" "<<b3.back()<<endl;

    StrBlobPtr sbp(b1);
    cout<<"b1 all element: "<<endl;
    for(auto c = b1.begin() ; c != b1.end(); c.incr())  //b1.begin() 返回的是临时对象
    {
        cout<<c.deref()<<endl;
    }

    return 0;
}
