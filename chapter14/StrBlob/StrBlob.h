#ifndef STRBLOB_H_INCLUDED
#define STRBLOB_H_INCLUDED

#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <initializer_list>

//����һ����
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

    StrBlob(const StrBlob &rhs):data(std::make_shared<std::vector<std::string>>(*rhs.data)){}  //�������캯��
    StrBlob& operator=(const StrBlob &);  //������ֵ�����

    StrBlob(StrBlob &&rhs)noexcept:data(std::move(rhs.data)){}  //�ƶ����캯��
    StrBlob& operator=(StrBlob &&)noexcept;  //�ƶ���ֵ�����

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const std::string& s){data->push_back(s);}
    //��ֵ���ð汾
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
    //�ǳ����汾
    std::string &operator[](size_t n){
        check(n,"out of range");
        //return (*data)[n];  �Լ���д����û�뵽at����
        return data->at(n);
    }
    //�����汾
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
    StrBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz){}  //���ܰ󶨵�const StrBlob����,��Ϊ���캯������һ����const StrBlob���������  2018-11-22 21:20:00

    bool operator!=(const StrBlobPtr& p){return p.curr!= curr;}

    std::string& deref() const {
        auto p = check(curr,"dereference past end");
        return (*p)[curr];  //�����÷���shared_ptr�����vector,Ȼ��ʹ���±��������ȡcurrλ���ϵ�Ԫ��
    }


    //practice14.26
    //�ǳ����汾
    std::string &operator[](size_t n){
        auto p = check(n,"out of range");
        return (*p)[n];
    }

    const std::string &operator[](size_t n)const{
        auto p = check(n,"out of range");
        return (*p)[n];
    }


    //ǰ׺���������ص�����Ķ��������
    StrBlobPtr& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

    //14.6����ǰ�õ����ݼ������  ͬpractice14.27
    //Ϊ�������ð汾����һ�£�ǰ�������Ӧ�÷��ض��������
    StrBlobPtr & operator++();
    StrBlobPtr & operator--();

    //���ð汾�ĵ����ݼ�����������ص���ԭֵ
    StrBlobPtr operator++(int);
    StrBlobPtr operator--(int);

    //practice 14.28
    StrBlobPtr& operator+=(size_t);
    StrBlobPtr& operator-=(size_t);
    StrBlobPtr operator+(size_t)const;  //practice14.28
    StrBlobPtr operator-(size_t)const;

    //14.7��ӽ���������� * �ͼ�ͷ�����  ->       ͬʱҲ��practice14.30
    //�����������ͨ��Ҳ����ĳ�Ա�����ܲ��Ǳ������
    std::string &operator*()const{
        auto p = check(curr,"dereference past end");
        return (*p)[curr];  //(*p)�Ƕ�����ָ��vector
    }

    //��ͷ�������ִ���κ��Լ��Ĳ��������ǵ��ý���������������ؽ����ý��Ԫ�صĵ�ַ
    //��ͷ�������������ĳ�Ա
    std::string *operator->()const{
        //��ʵ�ʹ���ί�и������������
        return &this->operator*();  //ȡ��string��ָ��
    }


private:
    std::shared_ptr<std::vector<std::string>> check(size_t i,const std::string msg) const {
        auto ret = wptr.lock();  //wptr.ust_count() == 0 ���shared_ptr�����򷵻�һ��ָ��w�����shared_ptr
        if( !ret )  //����ǿ�
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


//2018-11-22 21:31:39  ���ConstStrBlobPtr
class ConstStrBlobPtr
{
    public:
    ConstStrBlobPtr():curr(0){}
    ConstStrBlobPtr(const StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz){}  //����Ĺ��캯���Ĳ�������const�汾��StrBlob  2018-11-22 21:39:14

    bool operator!=(const ConstStrBlobPtr& p){return p.curr!= curr;}

    string& deref() const {
        auto p = check(curr,"dereference past end");
        return (*p)[curr];  //�����÷���shared_ptr�����vector,Ȼ��ʹ���±��������ȡcurrλ���ϵ�Ԫ��
    }

    //ǰ׺���������ص�����Ķ��������
    ConstStrBlobPtr& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

    //practice14.30  ��Ϊ����StrBlob��const�汾�ģ����Է��ص�stringҲҪ��const�汾
    const std::string &operator*() const
    {
        auto p = check(curr,"dereference past end");
        return (*P)[curr];
    }

    const std::string *operator->()const
    {
        return &this->operator*();  //->�����ȼ���
    }


private:
    shared_ptr<vector<string>> check(size_t i,const string msg) const {
        auto ret = wptr.lock();  //wptr.ust_count() == 0 ���shared_ptr�����򷵻�һ��ָ��w�����shared_ptr
        if( !ret )  //����ǿ�
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
