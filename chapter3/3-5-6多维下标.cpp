#include <iostream>
#include <string>
#include <typeinfo>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    /*
    1. 可以使用下标运算符来访问多维数组的元素，此时数组的每个维度对应一个下标运算符。
    如果表达式含有的下标运算符数量和数组的维度一样多，该表达式的结果将是给定类型的元素；
    反之，如果表达式含有的下标运算符数量比数组的维度小，则表达式的结果将是给定索引处的一个内层数组：
    */
    int ia1[3][4] = {0};
    int ia2[10][20][30] = {1};


    ia1[0][1] = ia2[0][0][0];  //下标运算符和数组维度一样多
    /*
        表达式提供的下标运算符数量和他们各自的维度相同
        在等号的左侧 ia[2]得到数组ia的最后一行，此时返回表示ia最后一行的那个一维数组而非实际元素，
        然后再对这个一维数组取下标得到编号为3的元素，也就是这一行的最后一个元素，等号右侧同理
    */
    int (&row)[4] = ia1[1];  //下标运算符数量小于数组的维度
    /*
        把row定义成一个含有4个整数的数组的引用，然后绑定到ia的第二行
    */
    for(const auto &row :ia1)
    {
        for(auto col:row)
        {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    constexpr size_t rowCnt = 3,colCnt = 4;
    int ia3[rowCnt][colCnt];
    /*
    for(size_t i = 0;i != rowCnt;i++)
    {
        for(size_t j = 0;j != colCnt;j++)
        {
            ia3[i][j] = i*colCnt + j;
        }
    }
    */
    //C++11新标准 使用范围for语句也能达到上面效果
    size_t cnt = 0;
    for(auto &row : ia3)  //外层的每个元素
    {
        cout<<typeid(row).name()<<endl;
        for(auto &col :row)  //内层的每个元素
        {
            col = cnt;
            cnt++;
        }
    }

    for(size_t i = 0; i != rowCnt; i++)
    {
        for(size_t j = 0; j != colCnt; j++)
        {
            cout<<'\t'<<&ia3[i][j]<<' ';
            //ia3[i][j] = i*colCnt + j;
        }
        cout<<endl;
    }

    /*
        范围for语句处理多维数组时，除了最内层的循环外，其他所有循环的控制变量都应是引用类型
        不用引用类型，编译器会初始化控制变量为指向数组首元素的指针
    */
    for(auto &row : ia3)  //外层的每个元素
    {//row一定要用引用类型，不然row将被初始化成指向数组arr首元素的指针，将导致auto col:row语句是非法的。
        for(auto col :row)  //内层的每个元素
        {
            cout<<col<<' ';
        }
        cout<<endl;
    }
    return 0;
}
