#include <iostream>
#include "StrVec.h"
using namespace std;

int main()
{


    StrVec s1({"hello","world","C++"});
    StrVec s2({"hello","world","C++"});
    StrVec s3({"Hello","Java"});
    cout<< (s1 == s2) <<endl;
    cout<< (s1 == s3) <<endl;
    cout<< (s1 != s3) <<endl;

    //14.5下标运算符  实验
    StrVec svec = {"","111","222"};
    const StrVec cvec = svec;

    if( svec.size() && svec[0].empty() )
    {
        svec[0] = "zero";
        //cvec[0] = "Zip";  对cvec取下标返回的是常量引用，常量引用不能改变值
    }
    cout<<svec[0]<<endl;
    cout<<cvec[0]<<endl;


    cout << "Hello world!" << endl;
    return 0;
}
