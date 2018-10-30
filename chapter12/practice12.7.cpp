#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

using Sptr = shared_ptr<vector<int>>;

shared_ptr<vector<int>> new_nums()
{
    shared_ptr<vector<int>> r = make_shared<vector<int>>();
    return r;
}

shared_ptr<vector<int>> use_nums(shared_ptr<vector<int>> p)
{
    int data;
    while(cin>>data)
    {
        p->push_back(data);
    }
    return p;
}

void print(shared_ptr<vector<int>> p)
{
    for(auto c : *p)
    {
        cout<<c<<" ";
    }
    cout<<endl;
}

int main()
{
    shared_ptr<vector<int>> grades = new_nums();
    use_nums(grades);
    print(grades);


    return 0;
}
