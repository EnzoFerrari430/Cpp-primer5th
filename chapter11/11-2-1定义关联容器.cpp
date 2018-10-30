#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
/*
    每个关联容器都定义了一个默认构造函数，它创建一个指定类型的空容器。
    我们也可以将关联容器初始化为另一个同类型的容器的拷贝
*/
int main()
{
    map<string,size_t> word_count;  //空容器

    //列表初始化
    set<string> exclude = {"the","but","and","or","an","a"};
    //将姓映射为名
    map<string,string> authors {
        {"Joyce","James"},
        {"Austen","Jane"},
        {"Dickens","Charles"}
    };

    return 0;
}
