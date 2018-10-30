#include <iostream>
#include <string>
#include <vector>
using namespace std;

//6.17 2者形参类型不同,要对字符串进行修改就不能用const
bool iSUp(const string &s)
{
    string::const_iterator sb;  //const string 类型的迭代要用string::const_iterator
    for(sb = s.begin() ;sb != s.end() ;++sb)
    {
        if( *sb >= 'A' && *sb <= 'Z')
        {
            return true;
        }
    }
    return false;
}

string lower(string &s)
{
    string::iterator sb;
    for(sb = s.begin() ; sb != s.end(); ++sb)
    {
        if( *sb >= 'A' && *sb <= 'Z')
            *sb = *sb + 'a' - 'A';
    }
    return s;
}

int main()
{
    /*
        6.16
        这个函数的参数是一个普通的string引用，不能传入字面值字符串,把参数改成const string &s

        6.18
        函数声明因为没有函数体，所以无需参数名字
        bool compare(matrix &mx1,matrix &mx2);
        vector<int>::iterator change_val(int n,vector<int>::iterator iv);

        6.19
        a.不合法 函数只有一个形参,这里是2个实参
        b.合法
        c.合法
        d.合法

        6.20
        不改变形参的时候应该使用常量引用
        可能会修改本来不需要改变的实参
    */

    string s("hello WoRld");
    cout<<iSUp(s)<<endl;
    cout<<lower(s)<<endl;
    return 0;
}
