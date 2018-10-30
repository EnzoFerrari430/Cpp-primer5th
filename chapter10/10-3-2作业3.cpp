#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

//10.18

string make_plural(size_t ctr,const string &word,const string &ending)
{
    return (ctr>1)? word + ending : word;
}


//形参使用引用,不然不改变任何东西
void elimDups(vector<string> &words)
{
    //按字典序排序
    sort(words.begin(),words.end());

    //unique 重排单词，返回不重复区域的后一个位置的迭代器
    auto end_unique = unique(words.begin(),words.end());

    //删除重复单词
    words.erase(end_unique,words.end());

}

void biggies(vector<string> words,int sz)
{
    //按字典序排序并且删除重复单词
    elimDups(words);

    //按长度排序，长度一样再按字典序排序
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b){return a.size() < b.size();} );

    //排完序后查找第一个大于等于sz的元素,
    //partition的谓词为true的会排在容器的前半部分，false会排在容器的后半部分,返回false的第一个元素的迭代器
    auto wc =  partition(words.begin(),words.end(),[sz](const string &a){return a.size() >= sz;});

    //计算出 size >= sz 的元素的数目
    auto count = wc - words.begin();
    cout<< count <<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer"<<endl;

    //一对迭代器基本表示的返回基本都是左闭右开
    for_each(words.begin(),wc,[](const string &a){cout<<a<<' ';});
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
    biggies(vec,4);

    return 0;
}
