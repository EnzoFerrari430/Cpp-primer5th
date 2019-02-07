#include "Basket.h"
#include "GlobalFun.h"


//�������������������ӡ���嵥��Ȼ�󷵻ع�������������Ʒ���ܼ۸�
double Basket::total_receipt(std::ostream &os)const
{
    double sum = 0.0;  //����ʵʱ��������ܼ۸�

    //����һ����������ָ���һ���ؼ��ִ���k��Ԫ��
    //count�������عؼ��ֵ���k������
    for(auto iter = items.cbegin() ; iter  != items.cend() ; iter = items.upper_bound(*iter))
    {
        //����֪����ǰ��Basket��������һ���ùؼ��ֵ�Ԫ��
        //��ӡ���鼮��Ӧ����Ŀ
        sum += print_total(os,**iter,items.count(*iter));
    }
    os << "Total sale: "<<sum<<std::endl;
    return sum;
}
