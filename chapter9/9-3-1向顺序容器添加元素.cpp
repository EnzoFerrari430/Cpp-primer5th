#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;
/*
这些操作会改变容器的大小，array不支持这些操作
forward_list有自己专门版本的insert和emplace
forward_list不支持push_back和emplace_back
vector和string不支持push_front和emplace_front

c.push_back(t)          在c的尾部创建一个值为t或由args创建的元素。返回void
c.emplace_back(args)

c.push_front(t)
c.emplace_front(args)   在c的头部创建一个值为t或由args创建的元素。返回void

c.insert(p,t)
c.emplace(p,args)       在迭代器p指向的元素之前创建一个值为t或由args创建的元素。返回指向新添加的元素的迭代器

c.insert(p,n,t)         在迭代器p指向的元素之前插入n个值为t的元素。返回指向新添加的第一个元素的迭代器：若n为0，则返回p

c.insert(p,b,e)         将迭代器b和e指定返回内的元素插入到迭代器p指向的元素之前。b和e不能指向c中的元素。返回指向新添加的第一个元素的迭代器
                        若范围为空，则返回p

c.inert(p,il)           il是一个花括号包围的元素值列表。将这些给定值插入到迭代器p指向的元素之前。返回指向新添加的第一个元素的迭代器
                        若列表为空，则返回p

★FBI warning:向一个vector、string或deque插入元素会使所有指向容器的迭代器、引用和指针失效


push_back ：除了array和forward_list之外 每个顺序容器（包括string）都支持push_back
push_front ：list、forward_list和deque容器支持名为push_front
*/
int main()
{
    vector<int> vi{2,4,6,8,10};
    vi.emplace(vi.begin()+1,1301050224);
    for(auto c:vi)
    {
        cout<<c<<' ';
    }
    cout<<endl;

    list<int> il;
    for(size_t ix = 0;ix!= 4;++ix)
    {
        il.push_front(ix);
    }
    for(auto c:il)
    {
        cout<<c<<' ';
    }
    cout<<endl;


    return 0;
}
