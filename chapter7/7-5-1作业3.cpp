#include <iostream>
#include <string>
using namespace std;
class date
{
public:

    date():year("0000"),month("00"),day("00"){}
    date(string y,string m,string d){year = y;month = m;day = d;}
    string year;
    string month;
    string day;
};

int main()
{
    date d1;
    cout<<d1.year<<'-'<<d1.month<<'-'<<d1.day;
    cout<<endl;
    date d2("2017","10","11");
    cout<<d2.year<<'-'<<d2.month<<'-'<<d2.day;
    return 0;
}
