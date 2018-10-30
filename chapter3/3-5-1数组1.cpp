#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    //数组如果维度比提供的初始值数量大，则用提供的初始值初始化靠前的数组，剩下的元素被初始化成默认值
    int a[3];

    const unsigned sz = 3;
    int a1[sz] = {0,1,2};
    int a2[] = {0,1,2};
    int a3[5] = {0,1,2};  //等价于a3[] = {0,1,2,0,0}
    string a4[3] = {"hi","bye"};  //等价于a4[] = {"hi","bye",""}
    //int a5[2] = {0,1,2};  wrong初始化值过多

    //字符串字面值会在结尾处加一位\0
    char c1[] = {'c','+','+'};  //列表初始化，没有空字符
    char c2[] = {'c','+','+','\0'};  //列表初始化，含有显示的空字符
    char c3[] = "C++";  //会自动添加表示字符串结束的空字符
    //const char c4[6] = "Daniel";  wrong字符串字面值会在结尾多加个\0，c4[6]的空间不够存储

    //数组不允许拷贝和赋值
    int d1[] = {0,1,2};
    //int d2[] = d1;  不允许用一个数组初始化另一个数组
    //d2 = d1;  不能把一个数组直接赋值给另一个数组

    int arr[10];
    int *ptr[10];    //ptrs是含有10个整型指针的数组
    //由右向左：定义一个大小为10的数组，名字是ptr，里面存放的是指向int的指针
    //int &refs[10] =   ;  //不存在引用的数组
    int (*Parray)[10] = &arr;  //Parray指向一个含有10个整数的数组
    //由内向外：定义一个Parray的指针，指向一个大小为10的数组，数组的元素是int
    int (&arrRef)[10] = arr;   //arrRef引用含有10个整数的数组
    //与上面同理
    int *(&arry)[10] = ptr;  //arry含有10个int型指针数组的引用




    return 0;
}
