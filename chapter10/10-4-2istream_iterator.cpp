#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
/*
    一个istream_iterator使用>>来读取流。
    istream_iterator要读取的类型必须定义了输入运算符
    创建istream_iterator时，我们可以将它绑定到一个流。
    默认初始化时，创建的是表示尾后值的迭代器


    istream_iterator<int> int_it(cin)  //从cin读取int
    istream_iterator<int> int_eof;  //尾后迭代器
    ifstream in("afile");
    istream_iterator<string> str_it(in);  //从"afile"读取字符串

istream_iterator的懒惰求值
    我们将一个istream_iterator绑定到一个流时，标准库并不保证迭代器立即从流读取数据。知道我们使用迭代器时才真正读取。


*/
int main()
{
    /*
    1.
    //读取数据存入vector
    vector<int> vec;
    istream_iterator<int> in_iter(cin);  //从cin读取int
    istream_iterator<int> eof;  //istream尾后迭代器
    while(in_iter != eof )  //当有数据可供读取时
    {
        //先解引迭代器，然后存入vec，最后自增迭代器
        vec.push_back(*in_iter++);
    }
    */

    //2.重写
    istream_iterator<int> in_iter(cin),eof;

    /*
    //不注释会先存入vec中,就得不到计算值
    vector<int> vec(in_iter,eof);
    for(auto c: vec)
        cout<<c<<' ';
    cout<<endl;
    */
    int num;
    cin>>num;
    cout<<num<<endl;

    cout<<accumulate(in_iter,eof,0)<<endl;

    return 0;
}
