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
            //case 'f':  //��������ͷ����Ϊ�����ͷ�Ļ�β�ͻ�δ���룬�޷������б�,Ӧ�����ж�β,�ٸ���β�ж�ͷ
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
        bech = ch;  //�����ڵ�ch����bech
    }
    cout<<ff_cnt<<endl;
    cout<<fl_cnt<<endl;
    cout<<fi_cnt<<endl;

    /*
        5-13
(a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0;
    char ch = next_text();
    switch (ch) {
    case 'a': aCnt++;  //���û��break;
    case 'e': eCnt++;
    default: iouCnt++;
    }

(b) unsigned index = some_value();
    switch (index) {
    case 1:
    int ix = get_value();  //ixҪ���ⲿ���壬���߶��岻���ҳ�ʼ��
    ivec[ ix ] = index;
    break;
    default:
    ix = ivec.size()-1;
    ivec[ ix ] = index;
    }


(c) unsigned evenCnt = 0, oddCnt = 0;
    int digit = get_num() % 10;
    switch (digit)  //����ż�Ļ� switch(digit%2) �����ֻ��case 1��case 0
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
    case ival:  //case��ǩ���������ͳ������ʽ
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
