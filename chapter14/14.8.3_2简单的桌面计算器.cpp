#include <iostream>
#include <map>
#include <functional>
using namespace std;
/*
    �ɵ��ö���ֱ�������ִ���˲�ͬ��������㣬�������ǵ����͸�����ͬ�����ǿ��Թ���ͬһ�ֵ�����ʽ int(int,int)
    ʹ��map����ʾ���ŵ�string������Ϊ�ؼ��֣�ʹ��ʵ��������ĺ�����Ϊֵ��
*/
//��ͬ���Ϳ��ܾ�����ͬ�ĵ�����ʽ
//��ͨ����
int add(int i,int j){return i+j;}
//lambda,�����һ��δ�����ĺ���������
auto mod = [](int i,int j){return i % j;};
/*
    lambda�����Լ��������ͣ� ��������洢��binops�е�ֵ�����Ͳ�ƥ��
    ������һ����Ϊfunction���±�׼�����ͽ���������⣬function������functionalͷ�ļ���

    function��һ��ģ�壬������ʹ�ù�������ģ��һ����������һ�������function����ʱ���Ǳ����ṩ�������Ϣ��
    �ڴ����У�������Ϣ��ָ��function�����ܹ���ʾ�Ķ���ĵ�����ʽ��
*/
//����������
struct divide
{
    int operator()(int denominator,int divisor){
        return denominator / divisor;
    }
};

function<int(int,int)> f1 = add;
function<int(int,int)> f2 = divide();  //����һ��divide����ʱ����
function<int(int,int)> f3 = [](int i,int j){ return i * j; };



int main()
{
    cout<<f1(4,2)<<endl;
    cout<<f2(4,2)<<endl;
    cout<<f3(4,2)<<endl;
//    //�����������������ָ���ӳ���ϵ�����к�������2��int����һ��int
//    map<string,int(*)(int,int)> binops;
//    //��add��ָ����ӵ�binops�С�
//    binops.insert({"+",add});  //{"+",add}��һ��pair
//��functionģ�����¶���map
    map<string,function<int(int,int)>> binops = {
        { "+",add },                                //����ָ��
        { "-",std::minus<int>() },                  //��׼�⺯������
        { "/",divide() },                           //�û�����ĺ�������
        { "*",[](int i,int j){return i*j;} },       //δ������lambda
        { "%",mod },                                //�����˵�lambda����
    };

    cout<<binops["+"](10,5)<<endl;  //����add(10,5)
    cout<<binops["-"](10,5)<<endl;  //ʹ��minus<int>����ĵ��������
    cout<<binops["/"](10,5)<<endl;  //ʹ��divide����ĵ��������
    cout<<binops["*"](10,5)<<endl;  //����lambda����
    cout<<binops["%"](10,5)<<endl;  //����lambda��������


    return 0;
}
