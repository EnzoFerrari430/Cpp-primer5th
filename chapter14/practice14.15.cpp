#include <iostream>
#include <string>
using namespace std;

class date
{
    friend int operator-(date &,date &);  //practice14.15  计算2个日期之差
    friend istream& operator>>(istream&,date &);  //practice14.12
public:

    date():year("0000"),month("00"),day("00"){}
    date(string y,string m,string d){year = y;month = m;day = d;}

    friend bool operator==(const date&,const date&);

    string year;
    string month;
    string day;
};

bool operator==( const date &lhs,const date &rhs )
{
    if( lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day )
    {
        //cout<<"equal"<<endl;
        return true;
    }
    else
    {
        cout<<"not equal"<<endl;  //奇怪了,不加这句0输出不了。。。
        return false;
    }
}

istream& operator>>(istream &input,date &rhs)
{
    input>>rhs.year>>rhs.month>>rhs.day;
    if(!input)
    {
        rhs = date();
    }
    return input;
}

int operator-(date &lhs,date &rhs)
{
    int y = atoi(lhs.year.c_str()) - atoi(rhs.year.c_str());
    int m = atoi(lhs.month.c_str()) - atoi(rhs.month.c_str());
    int d = atoi(lhs.day.c_str()) - atoi(rhs.day.c_str());
    return (y*365 + m*30 + d);
}

int main()
{
    //能比较！！！但是比较的是什么东西
    if( "cobble" == "stone" )
    {
        cout<<"hhh"<<endl;
    }
    else
    {
        cout<<"nnn"<<endl;
    }
    bool flag;
    date d1;
    cout<<d1.year<<'-'<<d1.month<<'-'<<d1.day;
    cout<<endl;
    date d2("2017","10","11");
    cout<<d2.year<<'-'<<d2.month<<'-'<<d2.day;
    flag = (d1==d2);
    cout<< flag <<endl;

    cout<< (d2 - d1) <<endl;


    return 0;
}
