#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;
/*
    ���������ڴ洢����֯Ϊһ��Ͱ��ÿ��Ͱ����0������Ԫ�ء���������ʹ��һ����ϣ������Ԫ��ӳ�䵽Ͱ��Ϊ�˷���һ��Ԫ�أ��������ȼ���Ԫ�ص�
    ��ϣֵ����ָ��Ӧ�������ĸ�Ͱ�������������ض���ϣֵ������Ԫ�ض���������ͬ��Ͱ�С���������ظ��ؼ��֣���ô���о�����ͬ�ؼ��ֵ�Ԫ��
    Ҳ������ͬһ��Ͱ�С��������������������ڹ�ϣ������������Ͱ�������ʹ�С

    ��������£���ϣ�������ܽ�ÿ���ض���ֵӳ�䵽Ψһ��Ͱ��

���������������
    Ͱ�ӿ�
    c.bucket_count()        ����ʹ�õ�Ͱ����Ŀ
    c.max_bucket_count()    ���������ɵ����Ͱ����Ŀ
    c.bucket_size(n)        ��n��Ͱ���ж��ٸ�Ԫ��
    c.bucket(k)             �ؼ���Ϊk��Ԫ�����ĸ�Ͱ��

    Ͱ����
    local_iterator          ����Ͱ��Ԫ�صĵ���������
    const_local_iterator    Ͱ��������const�汾
    c.begin(n) c.end(n)     Ͱn����Ԫ�ص�������β�������
    c.cbegin(n) c.cend(n)   const�汾

    ��ϣ����
    c.load_factor()         ÿ��Ͱ��ƽ��Ԫ������������floatֵ
    c.max_load_factor()     c��ͼά����ƽ��Ͱ��С������floatֵ��c������Ҫʱ����µ�Ͱ����ʹ��load_factor <= max_load_factor
    c.rehash(n)             ����洢��ʹ��bucket_count >= n����bucket_count > size/max_load_factor
    c.reserve(n)            ����洢��ʹ��c���Ա���n��Ԫ���Ҳ���rehash
*/


struct Sales_data
{
    //�³�Ա������Sales_data����Ĳ���
    string isbn() const{return bookNo;}
    //�ڳ�Ա�����ڲ������ǿ���ֱ��ʹ�õ��øú����Ķ���ĳ�Ա��������ͨ�������������������һ��
    //isbn��ʽ��ʹ��thisָ���Ա �൱�� return this->bookNo;
    //����ú����Ķ���ĵ�ַ��ʼ��this

    //�����б�֮���const�ؼ���,������������޸���ʽthisָ�������
    //Ĭ�������this��������ָ�������ͷǳ����汾�ĳ���ָ��
    //��Sales_data��Ա�����У�this��������Sales_data *const  this����ĵ�ַ���ܸģ�����*this���Ը�.
    //������Ĭ�������thisָ�벻�ܰ󶨵�һ������������
    //����Ҫ��thisָ�������� const Sales_data *const������ߺ����������
    //��Ϊthis���ڲ����б��У�����C++�﷨�����const�ؼ��ַ��ڳ�Ա�����Ĳ����б�֮��
    //����this�ͳ���ָ������ָ�룬����isbn���Զ�ȡ���Ķ���ĳ�Ա ���ǲ���д����ֵ
    //�����const�����ж�

    Sales_data &combine(const Sales_data &);  //ģ�¸�ֵ���㣬���������õ�����ֵ����
    double avg_price() const;

    //���ݳ�Ա
    string bookNo;
    unsigned units_sold = 0;  //���������϶�˵��ĳ�Ա�������岻����ֱ�ӳ�ʼ��   ����������
    double revenue = 0;
};



//Sales_data�ķǽӿڳ�Ա����
Sales_data add(const Sales_data &,const Sales_data &);
std::ostream &print(std::ostream &,const Sales_data &);
std::istream &read(std::istream &,Sales_data &);

Sales_data &Sales_data::combine(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;  //��rhs�ĳ�Ա�ӵ�this����ĳ�Ա��
    revenue += rhs.revenue;
    return *this;  //���ص��øú����Ķ���
}

//�����Ҫ���Լ���������������ؼ��ֵĻ�����Ҫ����һ����ϣֵ�����غ�������һ������ == ������ıȽϺ���
size_t hasher(const Sales_data &sd)
{
    return hash<string>()(sd.isbn());
    /*
��һ����������һ��hasher,Ȼ��ڶ���������������
�൱��

std::hash<string> hasher;
return hasher(sd.isbn());

����ѧǰ�˵ĺ�����ʱ���м�������д��
*/
}

bool eqOp(const Sales_data &lhs,const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}


int main()
{
    //ͨ����Щ��������һ��  unordered_multiset
    using SD_multiset = unordered_multiset<Sales_data,decltype(hasher)*,declval(eqOp)*>;
    //������Ͱ��С����ϣ����ָ�롢������ж������ָ��
    SD_multiset bookstore(42,hasher,eqOp);
    return 0;
}
