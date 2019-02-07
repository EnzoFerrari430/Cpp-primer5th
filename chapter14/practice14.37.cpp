#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class IsEqual
{
public:
    IsEqual(int v):value(v){  cout<<"construct: "<<value<<endl;}
    bool operator()(int elem){
        cout<<"operator()"<<endl;
        return elem == value;

    }


private:
    int value;


};

/*
template < class ForwardIterator, class Predicate, class T >
  void replace_if ( ForwardIterator first, ForwardIterator last,
                    Predicate pred, const T& new_value )
{
  for (; first != last; ++first)
    if (pred(*first)) *first=new_value;
}
传入IsEqual的构造函数  构造一个临时对象
后面在replace_if函数体内，循环调用IsEqual.operator()(elem)

*/

int main()
{
    vector<int> vec = {3,2,1,4,3,7,8,6};
    replace_if(vec.begin(),vec.end(),IsEqual(3),5);
    for(auto c:vec)
    {
        cout<<c<<" ";
    }
    cout<<endl;

}
