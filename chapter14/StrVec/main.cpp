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

    //14.5�±������  ʵ��
    StrVec svec = {"","111","222"};
    const StrVec cvec = svec;

    if( svec.size() && svec[0].empty() )
    {
        svec[0] = "zero";
        //cvec[0] = "Zip";  ��cvecȡ�±귵�ص��ǳ������ã��������ò��ܸı�ֵ
    }
    cout<<svec[0]<<endl;
    cout<<cvec[0]<<endl;


    cout << "Hello world!" << endl;
    return 0;
}
