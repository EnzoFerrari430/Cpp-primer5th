#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <deque>
#include <forward_list>
using namespace std;
/*
    C c(b,e) c初始化为b和e指定范围中元素的拷贝。范围中元素的类型必须与C的元素类型相容(array不适用)


    为了创建一个容器为另一个容器的拷贝，两个容器的类型及其元素类型必须匹配。不过，当传递迭代器参数来拷贝一个范围时，就不要求
    容器的类型是相同的了。而且，新容器和原容器中的元素类型也可以不同，只要能将要拷贝的元素转换为要初始化的容器的元素类型即可
*/
int main()
{
    list<string> authors = {"Milton","Shakespeare","Austen"};
    vector<const char *>articles = {"a","an","the"};

    list<string> list2(authors);
    //deque<string> authList(authors);  //error  容器类型不匹配
    //vector<string> words(articles);   //error  容器类型必须匹配

    //可以将const char*转换为string
    forward_list<const char *> words(articles.begin(),articles.end());
    for(auto c:words)
    {
        cout<<c<<' ';
    }

    return 0;
}
