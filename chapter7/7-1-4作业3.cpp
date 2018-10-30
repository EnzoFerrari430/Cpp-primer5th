#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct table
{
    int row = 0;
    int col = 4;

    //2ÖÖ·½Ê½
    //table() = default;
    table() : row(23),col(22){}


};

int main()
{
    table t1;
    cout<<t1.row<<" "<<t1.col<<endl;

    return 0;
}
