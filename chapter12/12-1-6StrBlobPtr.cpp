#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class StrBlobPtr;
class StrBlob
{
    friend class StrBlobPtr;
    StrBlobPtr begin(){return StrBlobPtr(*this);}
    StrBlobPtr end(){auto ret = StrBlobPtr(*this,data->size());
        return ret;
    }
};





int main()
{


    return 0;
}
