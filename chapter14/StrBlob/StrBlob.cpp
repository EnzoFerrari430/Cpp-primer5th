#include "StrBlob.h"

bool operator==(const StrBlob &lhs,const StrBlob &rhs)
{
    return *lhs.data == *rhs.data;  //判断内容是否相等.
}

bool operator!=(const StrBlob &lhs,const StrBlob &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs,const StrBlob &rhs)
{
    //按字典序比较2个序列的元素
    //所谓字典序比较，指的是两个序列分别从第一个开始一一按照字典序进行比较，如果相同位置的元素相同，则继续向后比较，直到相同位置出现不同的元素为止。
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
    //先判断自赋值
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


//StrBlobPtr部分
//StrBlobPtr部分
//StrBlobPtr部分

bool operator==(const StrBlobPtr &lhs,const StrBlobPtr &rhs)
{
    //先判断lhs和rhs是不是指向同一个元素
    auto l = lhs.wptr.lock(),r = rhs.wptr.lock();
    if( l == r )
    {
        //2个都为空，或者指向同一个元素，且位置相等
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
    //比较curr的大小
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

//14.16前置递增递减运算符
StrBlobPtr& StrBlobPtr::operator++()
{
    //如果curr已经指向了容器的尾后位置，则无法递增它
    check(curr,"increment past end of StrBlobPtr");
    ++curr;  //将在当前状态下向前移动一个元素
    return *this;
}

//小疑惑，这里的前置递增和前置递减为什么在顺序上有差别？？？？
StrBlobPtr& StrBlobPtr::operator--()
{
    //如果curr是0的话，则继续递减它会产生一个无效的下标
    --curr;
    check( curr,"decrement past begin of StrBlobPtr" );
    return *this;
}

//14.16后置版本
StrBlobPtr StrBlobPtr::operator++(int)  //这里的形参不需要命名
{
    //此处无需检查有效性，调用前置递增运算符时才需要检查
    StrBlobPtr ret = *this;
    ++*this;
    return ret;  //返回之前记录的状态
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    StrBlobPtr ret = *this;
    --*this;
    return ret;  // ！返回之前记录的状态
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
