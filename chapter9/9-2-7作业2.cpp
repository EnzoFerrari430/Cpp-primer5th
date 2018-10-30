#include <iostream>
#include <vector>
#include <list>
using namespace std;
//9.16
int main()
{
    list<int> li{0,1,2,3,4,5,6};
    vector<int> vi{3,3,3,3,3};

    if(*(li.begin()) > *(vi.begin()))
    {
        cout<<"Li's head is bigger than Vi's"<<endl;
    }
    else
    {
        cout<<"this not gonna happen"<<endl;
    }

    return 0;
}
//9.17  容器的类型要相同，保存的元素要相同而且可以进行比较操作
