/*

    14.3
        a) "cobble" == "stone"    2������const char* !!!�ܱȽ�
        b) svec1[0] == svec2[0]     string
        c) svec1 == svec2           vector
        d) svec1[0] == "stone"      "stone"ת����string  ��string�Ƚ�

    14.4
        a)  %       ����Ҫ�����Ա
        b)  %=      ���Ա
        c)  ++      ���Ա
        d)  ->      ���������Ա
        e)  <<      ����Ҫ�����Ա
        f)  &&      ����Ҫ�����Ա
        g)  ==      ����Ҫ�����Ա
        h)  ()      ���������Ա
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
        cout<<"not equal"<<endl;  //�����,�������0������ˡ�����
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
    //�ܱȽϣ��������ǱȽϵ���ʲô����
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
