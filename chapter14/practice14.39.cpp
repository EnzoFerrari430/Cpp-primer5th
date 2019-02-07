#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class countLength
{
public:
    countLength(size_t n1,size_t n2):low(n1),high(n2){}
    //��lambda������Ϊ�ɱ�ģ�Ӧ��ָ�ľ��������Ա,�����������Ͳ�����const����
    bool operator()(const string &s){
        return s.size() >= low && s.size() <= high;
    }
private:
    size_t low;
    size_t high;


};

class LengthNotLess
{
public:
    LengthNotLess(size_t n):sz(n){}
    bool operator()(const string &s){
        return s.size() > sz;
    }
private:
    size_t sz;
};

int main()
{
    string file("words.txt");
    fstream in(file);
    int a[10] = {0};
    vector<string> vs;
    while(in.eof() == 0)  //Ϊ������ѭ��
    {
        string str;
        in>>str;
        vs.push_back(str);
    }

//    for(int i = 1; i <= 10 ;++i)
//    {
//        cout<<"length is: "<<i<<"'s words are "<<count_if(vs.begin(),vs.end(),countLength(i))<<endl;
//    }

    cout<< "length are in range(1,9) number is: "<<count_if(vs.begin(),vs.end(),countLength(1,9))<<endl;
    cout<< "the number that word's length are larger than 10 is: "<<count_if(vs.begin(),vs.end(),LengthNotLess(10))<<endl;

    return 0;
}
