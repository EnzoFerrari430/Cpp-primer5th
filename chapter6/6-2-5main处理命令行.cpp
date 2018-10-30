#include <iostream>
#include <string>
using namespace std;
/*
★★★★★★★★★★★★★
需要给main()函数传递实参，之前写的程序基本上main()函数都是空形参列表
特殊点：使用argv中的实参时，一定要记得可选参数从argv[1]开始，argv[0]保存的是程序的名字。
*/
int main(int argc,char **argv)  //实参列表
{
    string str;
    for(int i = 1;i!= argc;++i)
    {
        str += argv[i];
        str += " ";
    }
    cout<<str<<endl;
    return 0;
}
