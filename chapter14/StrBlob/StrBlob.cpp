#include "StrBlob.h"

bool operator==(const StrBlob &lhs,const StrBlob &rhs)
{
    return *lhs.data == *rhs.data;  //�ж������Ƿ����.
}

bool operator!=(const StrBlob &lhs,const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs,const StrBlob &rhs)
{
    //���ֵ���Ƚ�2�����е�Ԫ��
    //��ν�ֵ���Ƚϣ�ָ�����������зֱ�ӵ�һ����ʼһһ�����ֵ�����бȽϣ������ͬλ�õ�Ԫ����ͬ����������Ƚϣ�ֱ����ͬλ�ó��ֲ�ͬ��Ԫ��Ϊֹ��
    return std::lexicographical_compare(lhs.data->begin(),lhs.data->end(),rhs.data->begin(),rhs.data->end());
}

bool operator>(const StrBlob &lhs,const StrBlob &rhs)
{
    return rhs < lhs;
}

bool operator<=(const StrBlob &lhs,const StrBlob &rhs)
{
    return !(lhs>rhs);
}

bool operator>=(const StrBlob &lhs,const StrBlob &rhs)
{
    return !(lhs<rhs);
}

StrBlob& StrBlob::operator=(const StrBlob &rhs)
{
    data = std::make_shared<std::vector<std::string>>(*rhs.data);
    return *this;
}

StrBlob& StrBlob::operator=(StrBlob &&rhs)noexcept
{
    //���ж��Ը�ֵ
    if(this != &rhs)
    {
        data = std::move(rhs.data);
        rhs.data = nullptr;
    }
    return *this;
}



StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
    return StrBlobPtr(*this,data->size());
}


//StrBlobPtr����
//StrBlobPtr����
//StrBlobPtr����

bool operator==(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    //���ж�lhs��rhs�ǲ���ָ��ͬһ��Ԫ��
    auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
    if( l == r )
    {
        //2����Ϊ�գ�����ָ��ͬһ��Ԫ�أ���λ�����
        return (!r || lhs.curr == rhs.curr);
    }
    else
    {
        return false;
    }
}

bool operator!=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    //�Ƚ�curr�Ĵ�С
    return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    return lhs.curr > rhs.curr;
}

bool operator<=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    return lhs.curr <= rhs.curr;
}

bool operator>=(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    return lhs.curr >= rhs.curr;
}

//14.16ǰ�õ����ݼ������
StrBlobPtr& StrBlobPtr::operator++()
{
    //���curr�Ѿ�ָ����������β��λ�ã����޷�������
    check(curr,"increment past end of StrBlobPtr");
    ++curr;  //���ڵ�ǰ״̬����ǰ�ƶ�һ��Ԫ��
    return *this;
}

//С�ɻ������ǰ�õ�����ǰ�õݼ�Ϊʲô��˳�����в�𣿣�����
StrBlobPtr& StrBlobPtr::operator--()
{
    //���curr��0�Ļ���������ݼ��������һ����Ч���±�
    --curr;
    check( curr,"decrement past begin of StrBlobPtr" );
    return *this;
}

//14.16���ð汾
StrBlobPtr StrBlobPtr::operator++(int)  //������ββ���Ҫ����
{
    //�˴���������Ч�ԣ�����ǰ�õ��������ʱ����Ҫ���
    StrBlobPtr ret = *this;
    ++*this;
    return ret;  //����֮ǰ��¼��״̬
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;  // ������֮ǰ��¼��״̬
}

//practice 14.28
StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{
    curr += n;
    check(curr,"increment out of range");
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{
    curr -= n;
    check(curr,"decrement out of range");
    return *this;
}


StrBlobPtr StrBlobPtr::operator+(size_t n)const
{
    StrBlobPtr ret = *this;
    ret += n;
    return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n)const
{
    StrBlobPtr ret = *this;
    ret -= n;
    return ret;
}
