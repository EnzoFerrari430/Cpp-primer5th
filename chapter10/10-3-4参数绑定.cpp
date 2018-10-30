#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>  //bind函数所在的头文件
using namespace std;
//using std::placeholders::_1;  //单个命名 _1 这样每个占位符名字都要提供一个单独的using声明,很麻烦
//using namespace namespace_name；形式说明希望所有来自namespace_name的名字都可以在我们的程序中直接使用
using namespace std::placeholers;

/*
    对于捕获局部变量的lambda，用函数来替换它就不是那么容易了，
    我们用在find_if调用中的lambda比较一个string和一个给定大小。我们可以很容易地编写一个完成相同工作的函数
*/
bool check_size(const string &s,string::size_type sz)
{
    return s.size() >= sz;
}

//但是，我们不能用这个函数作为find_if的一个参数。如前文所示，find_if接受一个一元谓词
//C++11新标准 使用一个新的名为bind的标准库函数，解决向check_size传递一个长度参数的问题,定义在头文件functional中
//bind函数可以看做是一个通用的函数适配器,接受一个可调用对象，生成新的可调用对象来”适应“原对象的参数列表
/*
    调用bind的一般形式
    auto newCallble = bind(callble,arg_list);
    其中newCallble本身是一个可调用对象，arg_list是一个逗号分隔的参数列表,对应给定的callble的参数。
    当我们调用newCallble时，newCallble会调用callble，并传递给它arg_list中的参数
    ★arg_list中的参数可能包含形如_n的名字，其中n是一个整数。这些参数是“占位符”，表示newCallble的参数,它们占据了传递给newCallble的参数的位置
    _1为newCallble的第一个参数，_2为第二个参数
*/
//绑定check_size的sz参数
//check6是一个可调用对象，接受一个string类型的参数
//并用此string和值6来调用check_size
auto check6 = bind(check_size,_1,6);
//此bind调用只有一个占位符，表示check6只接受单一参数。一元谓词
//占位符出现在arg_list的第一个位置。表示check6的此参数对应check_size的第一个参数。此参数是一个const string &。
//因此，调用check6必须传递给它一个string类型的参数，check6会将此参数传递给check_size
string s = "hello";
bool b1 = check6(s);  //check6(s) 会调用 check_size(s,6);
/*
    将基于lambda的find_if调用
    auto wc = find_if(words.begin(),words.end(),[sz](const string &a));

    替换为如下使用check_size的版本
    auto wc = find_if(words.begin(),words.end(),bind(check_size,_1,sz));
*/



int main()
{


    return 0;
}
