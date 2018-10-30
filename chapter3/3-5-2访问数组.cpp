#include <iostream>
#include <string>
#include <cstddef>  //数组下标size_t在这个头文件中定义
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main()
{
    //int a[11] = {};  //都被初始化为0

    unsigned score[11] = {};  //初始化为0
    unsigned grade;
    while(cin>>grade)
    {
        if(grade<=100)
        {
            score[grade/10]++;
        }
    }
    for(int c:score)
    {
        cout<<c<<" ";
    }
    return 0;
}
