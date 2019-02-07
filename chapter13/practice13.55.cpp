#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>
using namespace std;

//声明一个类
class StrBlobPtr;

class StrBlob
{
public:
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;

    //StrBlobPtr begin(){return StrBlobPtr(*this);}
    //StrBlobPtr end(){return StrBlobPtr(*this,data->size());}
    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob():data(make_shared<vector<string>>()){ }
    StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const string& s){data->push_back(s);}
    void pop_back(){
        check(0,"pop_back on empty StrBlob");
        data->pop_back();
    }

    string& front(){
        check(0,"front on empty StrBlob");
        return data->front();
    }

    string& back(){
        check(0,"back on empty StrBlob");
    }

    //13.55添加一个右值版本的push_back
    //书中解释说到，如果我们定义2个或以上具有同名字和相同参数列表的成员函数，就必须对所有函数都加上引用限定符
    void push_back( string &&s )
    {
        data->push_back(std::move(s));
    }

private:
    void check(size_type i,const string& msg) const {
        if(i>=data->size())
        {
            throw out_of_range(msg);
        }
    }

private:
    shared_ptr<vector<string>> data;

};

class StrBlobPtr
{
public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz){}

    bool operator!=(const StrBlobPtr& p){return p.curr!= curr;}

    string& deref() const {
        auto p = check(curr,"dereference past end");
        return (*p)[curr];  //解引用返回shared_ptr来获得vector,然后使用下标运算符提取curr位置上的元素
    }

    //前缀递增，返回递增后的对象的引用
    StrBlobPtr& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    shared_ptr<vector<string>> check(size_t i,const string msg) const {
        auto ret = wptr.lock();  //wptr.ust_count() == 0 则空shared_ptr，否则返回一个指向w对象的shared_ptr
        if( !ret )  //如果是空
        {
            throw runtime_error("unbound StrBlobPtr");
        }
        if(i>=ret->size())
        {
            throw out_of_range(msg);
        }
        return ret;
    }

    weak_ptr<vector<string>> wptr;
    size_t curr;

};

StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this,data->size());
}

int main()
{

    return 0;
}
