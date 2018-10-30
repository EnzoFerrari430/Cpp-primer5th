#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
using namespace std;
/*
顺序容器的删除操作
    这些操作会改变容器的大小，所以不适合array
    forward_list有特殊版本的erase
    forward_list不支持pop_back；vector和string不支持pop_front

    c.pop_back()        删除c中的尾元素。若c为空，则函数行为未定义。函数返回void
    c.pop_front()       删除c中的首元素。若c为空，则函数行为未定义。函数返回void
    c.erase(p)          删除迭代器p所指定的元素，返回一个指向被删元素之后元素的迭代器，若p指向尾元素，则返回尾后迭代器。若p是
                        尾后迭代器，则函数行为未定义
    c.erase(b,e)        删除迭代器b和e所指定返回内的元素。返回一个指向最后一个被删元素之后元素的迭代器，若e本身就是尾后迭代器，
                        则函数也返回尾后迭代器。
    c.clear()           删除c中的所有元素，返回void
*/
int main()
{
    vector<int> vi{1,2,3,4,5,6,7,8,9};
    vi.erase(vi.begin(),vi.end());
    for(auto c: vi)
        cout<<c<<' ';
    cout<<endl;


    return 0;
}
