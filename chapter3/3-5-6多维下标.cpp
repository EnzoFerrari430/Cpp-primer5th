#include <iostream>
#include <string>
#include <typeinfo>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    /*
    1. ����ʹ���±�����������ʶ�ά�����Ԫ�أ���ʱ�����ÿ��ά�ȶ�Ӧһ���±��������
    ������ʽ���е��±�����������������ά��һ���࣬�ñ��ʽ�Ľ�����Ǹ������͵�Ԫ�أ�
    ��֮��������ʽ���е��±�����������������ά��С������ʽ�Ľ�����Ǹ�����������һ���ڲ����飺
    */
    int ia1[3][4] = {0};
    int ia2[10][20][30] = {1};


    ia1[0][1] = ia2[0][0][0];  //�±������������ά��һ����
    /*
        ���ʽ�ṩ���±���������������Ǹ��Ե�ά����ͬ
        �ڵȺŵ���� ia[2]�õ�����ia�����һ�У���ʱ���ر�ʾia���һ�е��Ǹ�һά�������ʵ��Ԫ�أ�
        Ȼ���ٶ����һά����ȡ�±�õ����Ϊ3��Ԫ�أ�Ҳ������һ�е����һ��Ԫ�أ��Ⱥ��Ҳ�ͬ��
    */
    int (&row)[4] = ia1[1];  //�±����������С�������ά��
    /*
        ��row�����һ������4����������������ã�Ȼ��󶨵�ia�ĵڶ���
    */
    for(const auto &row :ia1)
    {
        for(auto col:row)
        {
            cout<<col<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
    constexpr size_t rowCnt = 3,colCnt = 4;
    int ia3[rowCnt][colCnt];
    /*
    for(size_t i = 0;i != rowCnt;i++)
    {
        for(size_t j = 0;j != colCnt;j++)
        {
            ia3[i][j] = i*colCnt + j;
        }
    }
    */
    //C++11�±�׼ ʹ�÷�Χfor���Ҳ�ܴﵽ����Ч��
    size_t cnt = 0;
    for(auto &row : ia3)  //����ÿ��Ԫ��
    {
        cout<<typeid(row).name()<<endl;
        for(auto &col :row)  //�ڲ��ÿ��Ԫ��
        {
            col = cnt;
            cnt++;
        }
    }

    for(size_t i = 0; i != rowCnt; i++)
    {
        for(size_t j = 0; j != colCnt; j++)
        {
            cout<<'\t'<<&ia3[i][j]<<' ';
            //ia3[i][j] = i*colCnt + j;
        }
        cout<<endl;
    }

    /*
        ��Χfor��䴦���ά����ʱ���������ڲ��ѭ���⣬��������ѭ���Ŀ��Ʊ�����Ӧ����������
        �����������ͣ����������ʼ�����Ʊ���Ϊָ��������Ԫ�ص�ָ��
    */
    for(auto &row : ia3)  //����ÿ��Ԫ��
    {//rowһ��Ҫ���������ͣ���Ȼrow������ʼ����ָ������arr��Ԫ�ص�ָ�룬������auto col:row����ǷǷ��ġ�
        for(auto col :row)  //�ڲ��ÿ��Ԫ��
        {
            cout<<col<<' ';
        }
        cout<<endl;
    }
    return 0;
}
