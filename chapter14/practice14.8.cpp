#include <iostream>
#include <string>
using namespace std;

class date
{
public:

    date():year("0000"),month("00"),day("00"){}
    date(string y,string m,string d){year = y;month = m;day = d;}

    friend bool operator==(const date&,const date&);
    friend ostream& operator<<(ostream&,const date&);

    string year;
    string month;
    string day;
};

bool operator==( const date &lhs,const date &rhs )
{
    if( lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day )
    {
        return true;
    }
    else
    {
        return false;
    }
}

ostream& operator<<(ostream& output,const date &rhs)
{
    output<<rhs.year<<" "<<rhs.month<<" "<<rhs.day;
    return output;
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
    cout<<endl;
    flag = (d1==d2);
    cout<< flag <<endl;
    cout<<d1<<endl;
    cout<<d2<<endl;

    return 0;
}
