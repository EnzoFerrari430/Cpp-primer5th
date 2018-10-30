#include <iostream>
using namespace std;
int main()
{
    int grade;
    cin>>grade;
    (grade<60)?cout<<'F'<<endl:(grade<70)?cout<<'D'<<endl:(grade<80)?cout<<'C'<<endl:(grade<90)?cout<<'B'<<endl:(grade<100)?cout<<'A'<<endl:cout<<"A++"<<endl;


    return 0;
}
