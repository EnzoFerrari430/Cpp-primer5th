#include <iostream>
#include <vector>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;
int main()
{
    /*
        严格说法，C++中没有多维数组，通常所说的多维数组其实是数组的数组，这点牢记，对以后理解使用有益.

    */
    //int ia[3][4];  //大小为3的数组，每个元素是含有4个整数的数组
    //按照由内向外的顺序理解，定义的名字是ia，是含有3个元素的数组，再往右看发现ia的元素也有自己的维度，
    //ia的元素本身又都是含有4个元素的数组，再看左边是int，所以这是一句：定义大小为3的数组，该数组的每个元素
    //都是含有4个整数的数组
    int arr[10][20][30] = {0};
    //大小为10的数组，它的每个元素都是大小为20的数组，这些数组的元素含有30个整数的数组

    //多维数组的初始化
    int ia[3][4] = { //3个元素，每个元素都是大小为4的数组
        {0,1,2,3},  //第一行初始值
        {4,5,6,7},  //第二行初始值
        {8,9,10,11} //第三行初始值
    };
    //cout<<ia[0][0]<<endl;
    /*
    for(auto c:ia)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    */
    //初始化每一行的第一个元素
    int i,j;
    int ia2[3][4] = {{0},{4},{8}};
    int ia3[3][4] = {0,3,6,9};  //初始化第一行元素，其他默认为0
    for(i = 0;i<3;i++)
    {
        for(j = 0;j<4;j++)
        {
            cout<<ia3[i][j]<<" ";
        }
        cout<<endl;
    }
    /*
    for(auto c:ia2)
    {
        cout<<c<<" ";
    }
    cout<<endl;
    */



    return 0;
}
