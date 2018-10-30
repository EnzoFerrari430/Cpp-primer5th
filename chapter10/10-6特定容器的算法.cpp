#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>
#include <iterator>
using namespace std;
/*
    链表不能随机访问元素，所以有些算法如排序需要交换2个元素，就不能用通用的算法，代价太大。
    链表版本的算法性能比对应通用版本的好得多

    list和forward_list成员函数版本的算法
    这些操作都范围void

    lst.merge(lst2)             将来自lst2的元素合并入lst。lst和lst2必须是有序的
    lst.merge(lst2,comp)        元素将从lst2元素删除。在合并之后，lst2变为空。第一个版本使用<运算符；第二个版本使用给定的比较操作
    lst.remove(val)             调用erase删除掉与给定值相等(==)
    lst.remove_if(pred)         或令一元谓词为真的每个元素
    lst.reverse()               反转lst中元素的顺序
    lst.sort()                  使用<或给定比较操作排序元素
    lst.sort(comp)
    lst.unique()                调用erase删除同一个值得连续拷贝。第一个版本使用==。第二个版本使用给定的二元谓词
    lst.unique(pred)


    链表类型的splice算法
    lst.splice(args)或flst.splice_after(args)

    args:
        (p,lst2)        p是指向lst中元素的迭代器或指向flst首前位置的迭代器函数将lst2的所有元素移动到lst中p之前的位置或flst中p位置之后
                        的位置，然后将元素从lst2中删除。lst2必须和lst或flst类型相同，且不能是同一个链表

        (p,lst2,p2)     p2是一个指向lst2中位置有效的迭代器。将p2指向的元素移动到lst中或者将p2之后的元素移动到flst中
                        lst2可以是与lst或flst相同的链表

        (p,lst2,b,e)    b,e必须表示lst2中的合法范围,将给定范围中的元素从lst2移动到lst或flst
                        lst2与lst或flst可以是相同的链表，但p不能指向给定范围的元素
*/
int main()
{


    return 0;
}
