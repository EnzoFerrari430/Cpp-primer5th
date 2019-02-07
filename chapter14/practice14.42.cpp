#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>  //标准库的函数对象
using namespace std;
using namespace std::placeholders;
int main()
{

    //practice14.42 a
    vector<int> vi = {123,123,123123,541321,123154,31564};
    cout<<std::count_if(vi.begin(), vi.end(), std::bind(std::greater<int>(), _1 , 1024))<<endl;

    //practice14.42 b
    vector<string> svec{"helloworld","asdasd","pooh"};
    cout<< *find_if(svec.begin(),svec.end(),std::bind( not_equal_to<string>(), _1,"pooh" ))<<endl;

    //practice14.42 c
    vector<int> vvi = {0,1,2,3,4,5,6};
    transform(vvi.begin(),vvi.end(),vvi.begin(),bind( multiplies<int>(), _1 , 2 ));

    for(auto c : vvi)
    {
        cout<<c<<" ";
    }
    cout<<endl;



    return 0;
}
