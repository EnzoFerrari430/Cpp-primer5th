/*

    14.3
        a) "cobble" == "stone"    2个都是const char* !!!能比较
        b) svec1[0] == svec2[0]     string
        c) svec1 == svec2           vector
        d) svec1[0] == "stone"      "stone"转换成string  用string比较

    14.4
        a)  %       不需要是类成员
        b)  %=      类成员
        c)  ++      类成员
        d)  ->      必须是类成员
        e)  <<      不需要是类成员
        f)  &&      不需要是类成员
        g)  ==      不需要是类成员
        h)  ()      必须是类成员
*/

#include <iostream>
#include <string>
using namespace std;

class date
{

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

    return 0;
}
