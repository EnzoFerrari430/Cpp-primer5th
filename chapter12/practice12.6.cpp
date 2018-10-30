#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int>* new_nums()
{
    vector<int> *p = new vector<int>();
    return p;
}

void use_nums(vector<int> *grade)
{
    int data;
    while(cin>>data)
    {
        grade->push_back(data);
    }
}

void print(vector<int> *grade)
{
    for(auto c : *grade)
    {
        cout<<c<<" ";
    }
    cout<<endl;
}



int main()
{
    vector<int> *ad = new_nums();
    use_nums(ad);
    print(ad);
    delete ad;
    return 0;
}
