#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;


/*
    Ϊ��ʹ����ģ�壬���Ǳ�����ģ������ļ��������ṩ�������Ϣ----��������ģ�������ģ��ʵ���б�

    vector����һ����ģ��
*/

//ʵ��12.1.1����StrBlob��ģ��汾������ΪBlob
//����ģ��Ķ����У����ǽ�ģ�����������������ʹ��ģ��ʱ�û���Ҫ�ṩ�����ͻ�ֵ
template <typename T>
class Blob
{
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    //���캯��
    Blob();
    Blob(std::initializer_list<T> il);
    //Blob��Ԫ�ص���Ŀ
    size_type size() const{return data->size();}
    bool empty()const{return data->empty();}
    //��Ӻ�ɾ��Ԫ��
    void push_back(const T& t){data->push_back(t);}
    //�ƶ��汾
    void push_back(T &&t){data->push_back(std::move(t));}
    void pop_back();
    //Ԫ�ط���
    T& back();
    T& operator[](size_type i);
private:
    std::shared_ptr<std::vector<T>> data;
    //��data[i]��Ч���׳�i
    void check(size_type i,const std::string &msg)const;
};
//Blobģ����һ����ΪT��ģ��������ͣ�������ʾBlob�����Ԫ�ص�����
//���û�ʵ����Blobʱ��T�ͻᱻ�滻Ϊ�ض���ģ��ʵ������


//���һ����Ա��������ģ����ڲ�����ó�Ա��������ʽ����Ϊ��������
//��ģ���ÿ��ʵ���������Լ��İ汾�ĳ�Ա������
//���Ҫ��������ģ���ⲿ�ĳ�Ա�����������Թؼ���template��ʼ�������ģ������б�

//����check��Ա
template <typename T>
void Blob<T>::check(size_type i,const std::string &msg)const
{
    if(i >= data->size())
    {
        throw std::out_of_range(msg);
    }
}

//�±��������back������ģ�����ָ���������ͣ���������
template <typename T>
T& Blob<T>::back()
{
    check(0,"back on empty Blob");
    return data->back();
}

template <typename T>
T& Blob<T>::operator[](size_type i)
{
    //���i̫����׳��쳣����ֹ����һ�������ڵ�Ԫ��
    check(i,"subscript out of range");
    return (*data)[i];
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0,"pop_back on empty Blob");
    data->pop_back();
}

//��������������ģ����ĳ�Աһ������ģ��Ĺ��캯������ҲҪ��ģ�������ʼ
template <typename T>
Blob<T>::Blob():data(std::make_shared<std::vector<T>>()){}

template <typename T>
Blob<T>::Blob(std::initializer_list<T> il):data(std::make_shared<std::vector<T>>(il)){}

int main()
{
    //ʹ����ģ��ʱ�����Ǳ����ṩ������Ϣ��
    //��Щ������Ϣ����ʾģ��ʵ���б����Ǳ��󶨵�ģ�������
    //������ʹ����Щģ��ʵ����ʵ�������ض�����
    Blob<int> ia;  //��Blob<int>
    Blob<int> ia2 = {0,1,2,3,4};  //��5��Ԫ�ص�Blob<int>
    //�������������ǵ�Blobģ��ʵ������һ����ʱ��������дBlobģ�壬��ģ�����T��ÿ��ʵ���滻Ϊ������ģ��ʵ�Σ��ڱ�������int


    //������ָ����ÿһ��Ԫ�����ͣ�������������һ����ͬ����
    Blob<string> names;     //����string��Blob
    Blob<double> prices;    //��ͬ��Ԫ������

    //Ĭ������£�һ����ģ��ĳ�Ա����ֻ�е������õ���ʱ�Ž���ʵ����
    //ʵ����Blob<int>�ͽ���initializer_list<int>�Ĺ��캯��
    Blob<int> squares = {0,1,2,3,4,5,6,7,8,9};
    //ʵ����Blob<int>::size()const
    for(size_t i = 0 ; i != squares.size() ; ++i)
    {
        squares[i] = i*i;  //ʵ����Blob<int>::operator[](size_t)
    }

    return 0;
}
