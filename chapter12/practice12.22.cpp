#include <fstream>
#include "practice12.22.h"

ConstStrBlobPtr StrBlob::begin() const
{
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const
{
    return ConstStrBlobPtr(*this,data->size());
}

int main()
{
    string infile("E:\\CC++\\C++ primer\\chapter12\\practice12.20.txt");
    ifstream in(infile);

    StrBlob blob;
    while(in.eof() == 0)
    {
        string str;
        getline(in,str);
        blob.push_back(str);
    }

    for(ConstStrBlobPtr pbeg(blob.begin()),pend(blob.end());pbeg != pend; pbeg.incr())
    {
        cout<<pbeg.deref()<<endl;
    }


    return 0;
}

