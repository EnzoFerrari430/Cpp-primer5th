#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
using namespace std;

//����һ����
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
        return (*p)[curr];  //�����÷���shared_ptr�����vector,Ȼ��ʹ���±��������ȡcurrλ���ϵ�Ԫ��
    }

    //ǰ׺���������ص�����Ķ��������
    StrBlobPtr& incr(){
        check(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }

private:
    shared_ptr<vector<string>> check(size_t i,const string msg) const {
        auto ret = wptr.lock();  //wptr.ust_count() == 0 ���shared_ptr�����򷵻�һ��ָ��w�����shared_ptr
        if( !ret )  //����ǿ�
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
    string infile("E:\\CC++\\C++ primer\\chapter12\\practice12.20.txt");
    ifstream in(infile);

    StrBlob blob;
    while(in.eof() == 0)
    {
        string str;
        getline(in,str);
        blob.push_back(str);
    }

    for(StrBlobPtr pbeg(blob.begin()),pend(blob.end());pbeg != pend; pbeg.incr())
    {
        cout<<pbeg.deref()<<endl;
    }

    return 0;
}
