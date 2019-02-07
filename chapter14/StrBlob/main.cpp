#include <iostream>
#include <fstream>
#include "StrBlob.h"
using namespace std;

int main()
{
    string infile("D:\\CC++\\C++primer\\chapter12\\practice12.20.txt");
    ifstream in(infile);

    StrBlob blob;
    while(in.eof() == 0)
    {
        string str;
        getline(in,str);
        blob.push_back(str);
    }

    for(StrBlobPtr pbeg(blob.begin()),pend(blob.end());pbeg != pend; pbeg.incr())
    {
        cout<<pbeg.deref()<<endl;
    }

    StrBlob blob2;
    blob2.push_back("helloworld");
    if( blob > blob2 )
    {
        for(StrBlobPtr iter = blob.begin() ;iter < blob.end() ; iter.incr())
        {
            cout<<iter.deref()<<" ";
        }
        cout<<endl;
    }

    StrBlob a1 = {"hi","bye","now"};
    StrBlobPtr p(a1);
    *p = "okay";
    cout<<p->size()<<endl;      //a1的首元素已经成了okay
    cout<<(*p).size()<<endl;

    return 0;
}
