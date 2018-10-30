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


//�β�ʹ������,��Ȼ���ı��κζ���
void elimDups(vector<string> &words)
{
    //���ֵ�������
    sort(words.begin(),words.end());

    //unique ���ŵ��ʣ����ز��ظ�����ĺ�һ��λ�õĵ�����
    auto end_unique = unique(words.begin(),words.end());

    //ɾ���ظ�����
    words.erase(end_unique,words.end());

}

void biggies(vector<string> words,int sz)
{
    //���ֵ���������ɾ���ظ�����
    elimDups(words);

    //���������򣬳���һ���ٰ��ֵ�������
    stable_sort(words.begin(),words.end(),[](const string &a,const string &b){return a.size() < b.size();} );

    //���������ҵ�һ�����ڵ���sz��Ԫ��,
    //partition��ν��Ϊtrue�Ļ�����������ǰ�벿�֣�false�����������ĺ�벿��,����false�ĵ�һ��Ԫ�صĵ�����
    auto wc =  partition(words.begin(),words.end(),[sz](const string &a){return a.size() >= sz;});

    //����� size >= sz ��Ԫ�ص���Ŀ
    auto count = wc - words.begin();
    cout<< count <<" "<<make_plural(count,"word","s")<<" of length "<<sz<<" or longer"<<endl;

    //һ�Ե�����������ʾ�ķ��ػ�����������ҿ�
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
