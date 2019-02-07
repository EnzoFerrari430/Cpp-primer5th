#ifndef STRBLOB_H_INCLUDED
#define STRBLOB_H_INCLUDED

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <initializer_list>

//声明一个类
class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
public:
    friend bool operator==(const StrBlob &,const StrBlob &);  //practice14.16
    friend bool operator!=(const StrBlob &,const StrBlob &);

    friend bool operator<(const StrBlob &,const StrBlob &);  //practice14.18
    friend bool operator>(const StrBlob &,const StrBlob &);
    friend bool operator<=(const StrBlob &,const StrBlob &);
    friend bool operator>=(const StrBlob &,const StrBlob &);

    using size_type = std::vector<std::string>::size_type;
    friend class StrBlobPtr;

    //StrBlobPtr begin(){return StrBlobPtr(*this);}
    //StrBlobPtr end(){return StrBlobPtr(*this,data->size());}
    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob():data(std::make_shared<std::vector<std::string>>()){ }
    StrBlob(std::initializer_list<std::string> il):data(std::make_shared<std::vector<std::string>>(il)){}

    StrBlob(const StrBlob &rhs):data(std::make_shared<std::vector<std::string>>(*rhs.data)){}  //拷贝构造函数
    StrBlob& operator=(const StrBlob &);  //拷贝赋值运算符

    StrBlob(StrBlob &&rhs)noexcept:data(std::move(rhs.data)){}  //移动构造函数
    StrBlob& operator=(StrBlob &&)noexcept;  //移动赋值运算符

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const std::string& s){data->push_back(s);}
    //右值引用版本
    void push_back( std::string &&s )
    {
        data->push_back(std::move(s));
    }
    void pop_back(){
        check(0,"pop_back on empty StrBlob");
        data->pop_back();
    }

    std::string& front(){
        check(0,"front on empty StrBlob");
        return data->front();
    }

    std::string& back(){
        check(0,"back on empty StrBlob");
    }

    //practice 14.26
    //非常量版本
    std::string &operator[](size_t n){
        check(n,"out of range");
        //return (*data)[n];  自己的写法，没想到at函数
        return data->at(n);
    }
    //常量版本
    const std::string &operator[](size_t n)const{
        check(n,"out of range");
        return data->at(n);
    }


private:
    void check(size_type i,const std::string& msg) const {
        if(i>=data->size())
        {
            throw std::out_of_range(msg);
        }
    }

private:
    std::shared_ptr<std::vector<std::string>> data;

};

class StrBlobPtr
{
    friend bool operator==(const StrBlobPtr &,const StrBlobPtr &);  //practice14.16
    friend bool operator!=(const StrBlobPtr &,const StrBlobPtr &);

    friend bool operator<(const StrBlobPtr &,const StrBlobPtr &);  //practice14.18
    friend bool operator>(const StrBlobPtr &,const StrBlobPtr &);
    friend bool operator<=(const StrBlobPtr &,const StrBlobPtr &);
    friend bool operator>=(const StrBlobPtr &,const StrBlobPtr &);


public:
    StrBlobPtr():curr(0){}
    StrBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz){}  //不能绑定到const StrBlob对象,因为构造函数接受一个非const StrBlob对象的引用  2018-11-22 21:20:00

    bool operator!=(const StrBlobPtr& p){return p.curr!= curr;}

    std::string& deref() const {
        auto p = check(curr,"dereference past end");
        return (*p)[curr];  //解引用返回shared_ptr来获得vector,然后使用下标运算符提取curr位置上的元素
    }


    //practice14.26
    //非常量版本
    std::string &operator[](size_t n){
        auto p = check(n,"out of range");
        return (*p)[n];
    }

    const std::string &operator[](size_t n)const{
        auto p = check(n,"out of range");
        return (*p)[n];
    }


    //前缀递增，返回递增后的对象的引用
    StrBlobPtr& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

    //14.6定义前置递增递减运算符  同practice14.27
    //为了与内置版本保持一致，前置运算符应该返回对象的引用
    StrBlobPtr & operator++();
    StrBlobPtr & operator--();

    //后置版本的递增递减运算符，返回的是原值
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);

    //practice 14.28
    StrBlobPtr& operator+=(size_t);
    StrBlobPtr& operator-=(size_t);
    StrBlobPtr operator+(size_t)const;  //practice14.28
    StrBlobPtr operator-(size_t)const;

    //14.7添加解引用运算符 * 和箭头运算符  ->       同时也是practice14.30
    //解引用运算符通常也是类的成员，尽管并非必须如此
    std::string &operator*()const{
        auto p = check(curr,"dereference past end");
        return (*p)[curr];  //(*p)是对象所指的vector
    }

    //箭头运算符不执行任何自己的操作，而是调用解引用运算符并返回解引用结果元素的地址
    //箭头运算符必须是类的成员
    std::string *operator->()const{
        //将实际工作委托给解引用运算符
        return &this->operator*();  //取到string的指针
    }


private:
    std::shared_ptr<std::vector<std::string>> check(size_t i,const std::string msg) const {
        auto ret = wptr.lock();  //wptr.ust_count() == 0 则空shared_ptr，否则返回一个指向w对象的shared_ptr
        if( !ret )  //如果是空
        {
            throw std::runtime_error("unbound StrBlobPtr");
        }
        if(i>=ret->size())
        {
            throw std::out_of_range(msg);
        }
        return ret;
    }

    std::weak_ptr<std::vector<std::string>> wptr;
    size_t curr;
};


//2018-11-22 21:31:39  添加ConstStrBlobPtr
class ConstStrBlobPtr
{
    public:
    ConstStrBlobPtr():curr(0){}
    ConstStrBlobPtr(const StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz){}  //这里的构造函数的参数接受const版本的StrBlob  2018-11-22 21:39:14

    bool operator!=(const ConstStrBlobPtr& p){return p.curr!= curr;}

    string& deref() const {
        auto p = check(curr,"dereference past end");
        return (*p)[curr];  //解引用返回shared_ptr来获得vector,然后使用下标运算符提取curr位置上的元素
    }

    //前缀递增，返回递增后的对象的引用
    ConstStrBlobPtr& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

    //practice14.30  因为这里StrBlob是const版本的，所以返回的string也要是const版本
    const std::string &operator*() const
    {
        auto p = check(curr,"dereference past end");
        return (*P)[curr];
    }

    const std::string *operator->()const
    {
        return &this->operator*();  //->的优先级高
    }


private:
    shared_ptr<vector<string>> check(size_t i,const string msg) const {
        auto ret = wptr.lock();  //wptr.ust_count() == 0 则空shared_ptr，否则返回一个指向w对象的shared_ptr
        if( !ret )  //如果是空
        {
            throw runtime_error("unbound ConstStrBlobPtr");
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



#endif // STRBLOB_H_INCLUDED
