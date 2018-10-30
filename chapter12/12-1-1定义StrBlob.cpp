#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;
/*
ĳЩ��������Դ������ԭ�����������������

ϣ������һ���࣬�����Ĳ�ͬ����֮�乲����ͬ��Ԫ��(��Ԫ�ط����ڴ��ͬһ���ط���������ָ��ָ����)���������ǿ���һ�������ʱ��ԭ�����俽��Ӧ��������ͬ�ĵײ�Ԫ��

���ǲ����ڶ�����ֱ�ӱ���vector����Ϊһ������ĳ�Ա�ڶ�������ʱҲ�ᱻ����
*/

//student�಻�ܹ���Ԫ��
class student
{
public:
    vector<int> m_nGrades;
    string m_sName;
};

//Ϊÿ��StrBlob����һ��shared_ptr������̬�����vector����shared_ptr�ĳ�Ա����¼�ж��ٸ�StrBlob������ͬ��vector��
//����vector�����һ��ʹ���߱�����ʱ�ͷ�vector
class StrBlob
{
public:
    typedef vector<string>::size_type size_type;
    StrBlob();
    StrBlob(initializer_list<string> il);
    size_type size() const
    {
        return data->size();   //ͨ�����е�data��Աʵ��
    }
    bool empty() const
    {
        return data->empty();   //const����:  ʹthis��һ��ָ������ָ��
    }

    //��Ӻ�ɾ��Ԫ��
    void push_back(const string &t)
    {
        data->push_back(t);
    }
    void pop_back();
    const void pop_back() const;
    //Ԫ�ط���
    string& front();
    const string& front() const;
    string& back();
    const string& back() const;


    shared_ptr<vector<string>> data;
    //���data[i]���Ϸ����׳�һ���쳣
    void check(size_type i,const string &msg) const;
};

//2�����캯����ʹ�ó�ʼ���б�����ʼ����data��Ա������ָ��һ����̬�����vector��Ĭ�Ϲ��캯������һ����vector
StrBlob::StrBlob():data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)) {}

//�ڷ��ʺ�ɾ��Ԫ�ص�ʱ��Ҫ���Ԫ���Ƿ����
void StrBlob::check(size_type i,const string &msg) const
{
    if( i >= data->size() )
    {
        throw out_of_range(msg);
    }
}

//ɾ���ͷ���ǰ���ȵ���check
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
    //b.m_sName = a.m_sName;  //����a�뿪�����򣬱�����
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
