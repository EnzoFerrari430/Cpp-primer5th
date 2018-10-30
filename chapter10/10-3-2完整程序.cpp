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


//���Ҵ���ָ�����ȵĵ�һ��Ԫ��
void biggis(vector<string> words,int sz)
{
    //��isShort���������ͬ���ܵ�lambda
    //���������򣬳�����ͬ�İ��ֵ�������
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b) -> bool {return a.size() < b.size();});

    //���������ҵ�һ�����ڵ���sz��Ԫ��,���ص�һ�����Ȳ�С��sz��Ԫ�صĵ�����
    auto wc = find_if(words.begin(),words.end(),[sz](const string &a){return a.size() >= sz;});  //��һ���� string���͵�a

    //����� size >= sz ��Ԫ�ص���Ŀ
    auto count = words.end() - wc;
    cout<< count <<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer"<<endl;

    //ʹ��for_each
    /*
        for_each��䣬�������ʽΪ:

template<class InputIterator, class Function>
   Function for_each(
      InputIterator _First,
      InputIterator _Last,
      Function _Func
   );
���У�_First�ǵ�������Ӧ��ʼԪ��λ�ã�_Last�ǵ�������Ӧ�Ľ���λ�ã������������п��Է��ʵ�λ�ã�
_Func���û�����ĺ������󣬽��ڵ�������Χ�ڵ�����Ԫ�أ���Ӧ�õ��ú����С�
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
