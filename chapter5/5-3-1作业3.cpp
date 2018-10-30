#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int get_value()
{
    srand((unsigned)time(0));  //随机数种子
    int n;
    n = rand()%100;
    return n;
}
/*
ival是if内部定义的，ival的作用域只在上面if规定的作用域内

改1.把下面的if 改成else if 这样上面的if作用域延伸到了下面
2.把ival的定义放在if的上面，这样ival的作用域就是整个函数
(c) if (int ival = get_value())
    cout << "ival = " << ival << endl;
    if (!ival)
    cout << "ival = 0\n";
*/

//悬垂else: C++规定，else与其最近的尚未匹配的if相匹配
int main()
{
    if(int ival = get_value())
        cout<< "ival = "<<ival<<endl;
    else if(!ival)
        cout<< "ival = 0\n";

    return 0;
}
