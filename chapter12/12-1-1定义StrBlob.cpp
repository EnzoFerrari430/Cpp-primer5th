#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
/*
某些类分配的资源具有与原对象相独立的生存期

希望定义一个类，类对象的不同拷贝之间共享相同的元素(把元素放在内存的同一个地方，让智能指针指向它)，即当我们拷贝一个类对象时，原对象及其拷贝应该引用相同的底层元素

我们不能在对象内直接保存vector，因为一个对象的成员在对象销毁时也会被销毁
*/

//student类不能共享元素
class student
{
public:
    vector<int> m_nGrades;
    string m_sName;
};

//为每个StrBlob设置一个shared_ptr来管理动态分配的vector。此shared_ptr的成员将记录有多少个StrBlob共享相同的vector，
//并在vector的最后一个使用者被销毁时释放vector
class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const
    {
        return data->size();   //通过类中的data成员实现
    }
    bool empty() const
    {
        return data->empty();   //const作用:  使this是一个指向常量的指针
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


    shared_ptr<vector<string>> data;
    //如果data[i]不合法，抛出一个异常
    void check(size_type i,const string &msg) const;
};

//2个构造函数都使用初始化列表来初始化其data成员，令它指向一个动态分配的vector。默认构造函数分配一个空vector
StrBlob::StrBlob():data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)) {}

//在访问和删除元素的时候，要检查元素是否存在
void StrBlob::check(size_type i,const string &msg) const
{
    if( i >= data->size() )
    {
        throw out_of_range(msg);
    }
}

//删除和访问前都先调用check
string& StrBlob::front()
{
    check(0,"front on empty StrBlob");
    return data->front();
}

const string& StrBlob::front() const
{
    check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}

const string& StrBlob::back() const
{
    check(0,"back on empty StrBlob");
    return data->back();
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

int main()
{
    student b;
    {
        student a;
        a.m_sName = "PJD";
        a.m_nGrades = {70,67,64,61,61,60};
    }
    //b.m_sName = a.m_sName;  //对象a离开作用域，被销毁
    //cout<<b.m_sName<<endl;
    StrBlob b1;
    {
        StrBlob b2 = {"a","an","the"};
        b1 = b2;
        b2.push_back("about");
    }
    cout<<b1.front()<<endl;
    cout<<b1.back()<<endl;
    return 0;
}
