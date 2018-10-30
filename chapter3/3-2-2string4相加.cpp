#include <iostream>
using namespace std;
int main()
{
    /*
        (+)2个string对象相加就是把左侧运算对象和右侧运算对象串接起来
        (+=)复合赋值运算就是把右侧string对象内容追加到左侧string对象的后面
    */
    string s1 = "hello ";
    string s2 = "world";
    string s3 = s1 + s2;
    //等价于s1 += s2;
    cout<<s3<<endl;

    //标准库允许把字符字面值和字符串字面值转换成string对象
    //string对象和字符字面值以及字符串字面值混在一条语句中时，必须保证 "+"号的两侧至少有一个string对象
    string s4 = "hello";
    string s5 = "world";
    string s6 = s4 + " " +s5;
    cout<<s6<<endl;

    //string s7 = "hello " + "world"; +号两侧没有string对象
    string s8 = s4 + ", " + "world";  //正确，因为s4 + ", " 操作能返回一个string对象

    //string s9 = "hello" + ", " + s5; //错误  因为"hello" + ", " 是字面值不能直接相加


    return 0;
}
