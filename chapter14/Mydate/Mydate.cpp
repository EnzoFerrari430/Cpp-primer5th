#include "Mydate.h"

bool operator==( const Mydate &lhs,const Mydate &rhs )
{
    if( lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day )
    {
        //cout<<"equal"<<endl;
        return true;
    }
    else
    {
        //cout<<"not equal"<<endl;  //�����,�������0������ˡ�����
        return false;
    }
}

bool operator!=(const Mydate &lhs,const Mydate &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const Mydate &lhs,const Mydate &rhs)
{
    //�Ƚ����
    if( lhs.year < rhs.year )
    {
        return true;
    }
    else if( lhs.year > rhs.year )
    {
        return false;
    }
    else
    {   //�Ƚ��·�
        if( lhs.month < rhs.month )
        {
            return true;
        }
        else if( lhs.month > rhs.month )
        {
            return false;
        }
        else
        {
            //�Ƚ�����
            if(lhs.day < rhs.day)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

bool operator>(const Mydate &lhs,const Mydate &rhs)
{
    return rhs<lhs;
}

bool operator<=(const Mydate &lhs,const Mydate &rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const Mydate &lhs,const Mydate &rhs)
{
    return !(lhs < rhs);
}

std::istream& operator>>(std::istream &input,Mydate &rhs)
{
    input>>rhs.year>>rhs.month>>rhs.day;
    if(!input)
    {
        rhs = Mydate();
    }
    return input;
}

int operator-(Mydate &lhs,Mydate &rhs)
{
    int y = atoi(lhs.year.c_str()) - atoi(rhs.year.c_str());
    int m = atoi(lhs.month.c_str()) - atoi(rhs.month.c_str());
    int d = atoi(lhs.day.c_str()) - atoi(rhs.day.c_str());
    return (y*365 + m*30 + d);
}

Mydate &Mydate::operator=(const Mydate &rhs)
{
    year = rhs.year;
    month = rhs.month;
    day = rhs.day;
    return *this;
}

Mydate &Mydate::operator=(Mydate &&rhs)noexcept
{
    //���ж��Ը�ֵ���
    if( this != &rhs )
    {
        year = std::move(rhs.year);
        month = std::move(rhs.month);
        day = std::move(rhs.day);
    }
    return *this;
}
