#include <iostream>
using namespace std;
int main()
{
    char ch,bech = '\0';
    int ff_cnt = 0,fl_cnt = 0,fi_cnt = 0;
    while(cin>>ch)
    {
        switch(ch)
        {
            //case 'f':  //不好先找头，因为输入的头的话尾就还未输入，无法二次判别,应该先判断尾,再根据尾判断头
        case 'f':
            if(bech == 'f')
            {
                ++ff_cnt;
            }
            break;
        case 'l':
            if(bech == 'f')
            {
                ++fl_cnt;
            }
            break;
        case 'i':
            if(bech == 'f')
            {
                ++fi_cnt;
            }
            break;
        }
        bech = ch;  //把现在的ch赋给bech
    }
    cout<<ff_cnt<<endl;
    cout<<fl_cnt<<endl;
    cout<<fi_cnt<<endl;

    /*
        5-13
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
    case 'a': aCnt++;  //语句没有break;
    case 'e': eCnt++;
    default: iouCnt++;
    }

(b) unsigned index = some_value();
    switch (index) {
    case 1:
    int ix = get_value();  //ix要在外部定义，或者定义不并且初始化
    ivec[ ix ] = index;
    break;
    default:
    ix = ivec.size()-1;
    ivec[ ix ] = index;
    }


(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit)  //求奇偶的话 switch(digit%2) 后面就只用case 1和case 0
    {
    case 1, 3, 5, 7, 9:
        oddcnt++;
        break;
    case 2, 4, 6, 8, 10:
        evencnt++;
        break;
    }

(d) unsigned ival=512, jval=1024, kval=4096;
    unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt)
    {
    case ival:  //case标签必须是整型常量表达式
        bufsize = ival * sizeof(int);
        break;
    case jval:
        bufsize = jval * sizeof(int);
        break;
    case kval:
        bufsize = kval * sizeof(int);
        break;
    }

    */

    return 0;
}
