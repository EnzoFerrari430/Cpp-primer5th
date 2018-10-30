#include <iostream>
using namespace std;
/*


*/
int ff(int a,int b = 0,int c = 0);
//char *init(int ht = 24,int wd,char bckgrnd);  错误 有默认值的形参后面的形参都要有默认值

char *init(int ht,int wd = 80,char bckgrnd = ' ');

string make_plural(size_t ctr,const string &word,const string &ending = "s")
{
    return ctr>1? word + ending:word;
}
int main()
{
    //init();  缺少参数
    //init(24,10);  //合法
    //init(14,'*'); //合法，但是'*'会转换成ascii码 传给wd
    cout<<make_plural(1,"tree","es")<<endl;
    cout<<make_plural(2,"table")<<endl;
    return 0;
}
