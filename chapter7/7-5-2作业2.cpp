#include <iostream>
#include <string>
using namespace std;
class date
{
public:

    date():year("0000"),month("00"),day("00"){cout<<"Ĭ�Ϲ��캯��"<<endl;}
    date(string y,string m,string d):year(y),month(m),day(d){cout<<"3�������캯��"<<endl;}

    date(string y):date(y,"01","01"){cout<<"ί�й��캯��1"<<endl;}
    date(string y,string m):date(y,m,"01"){cout<<"ί�й��캯��2"<<endl;}
    string year;
    string month;
    string day;
};

int main()
{
    date d1;

    date d2("2017");
    date d3("2017","10");
    date d4("2017","10","11");
    return 0;
}
