#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    const char ca1[] = "helloworld";
    const char ca2[] = "cplusplus";
    char ca3[100];
    strcpy(ca3,ca1);
    strcat(ca3," ");  //在末尾加上空格
    strcat(ca3,ca2);
    cout<<ca3<<endl;
    return 0;
}
