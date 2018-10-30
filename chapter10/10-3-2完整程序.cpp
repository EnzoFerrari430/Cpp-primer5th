#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


string make_plural(size_t ctr,const string &word,const string &ending)
{
    return (ctr>1)? word + ending : word;
}


//查找大于指定长度的第一个元素
void biggis(vector<string> words,int sz)
{
    //与isShort函数完成相同功能的lambda
    //按长度排序，长度相同的按字典序排序
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b) -> bool {return a.size() < b.size();});

    //排完序后查找第一个大于等于sz的元素,返回第一个长度不小于sz的元素的迭代器
    auto wc = find_if(words.begin(),words.end(),[sz](const string &a){return a.size() >= sz;});  //单一参数 string类型的a

    //计算出 size >= sz 的元素的数目
    auto count = words.end() - wc;
    cout<< count <<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer"<<endl;

    //使用for_each
    /*
        for_each语句，其语句形式为:

template<class InputIterator, class Function>
   Function for_each(
      InputIterator _First,
      InputIterator _Last,
      Function _Func
   );
其中，_First是迭代器对应起始元素位置，_Last是迭代器对应的结束位置，必须是序列中可以访问的位置，
_Func是用户定义的函数对象，将在迭代器范围内的所有元素，均应用到该函数中。
    */
    for_each(wc,words.end(),[](const string &s){cout<<s<<" ";});
    cout<<endl;

}

int main()
{
    string letter;
    vector<string> vec;
    while(cin>>letter)
    {
        vec.push_back(letter);
    }
    biggis(vec,4);



    return 0;
}
