#include <iostream>
using namespace std;
int main()
{
    char ch;
    unsigned num = 0,othernum = 0;
    while(cin>>ch)
    {
        switch(ch)
        {
        //一般不要省略case分支后面的break;语句。如果没写break最好加一段注释，说明这里的逻辑
        //default标签：如果没有任何一个case标签能匹配上switch表达式的值，程序将执行紧跟在default标签后面的语句.
        //例如，可以增加一个计数值来统计非元音字母的数量，只要在default分支内不断递增othernum的变量就可以了
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ++num;
            break;
        default:
            ++othernum;
            break;
        }
    }
    cout<<num<<endl;
    cout<<othernum<<endl;
    return 0;
}
