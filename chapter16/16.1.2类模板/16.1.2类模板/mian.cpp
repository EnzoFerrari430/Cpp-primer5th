#include "Blob.h"
#include "BlobPtr.h"
#include <Windows.h>
using namespace std;
int main()
{
	//ʹ����ģ��ʱ�����Ǳ����ṩ������Ϣ��
	//��Щ������Ϣ����ʾģ��ʵ���б����Ǳ��󶨵�ģ�������
	//������ʹ����Щģ��ʵ����ʵ�������ض�����
	Blob<int> ia;  //��Blob<int>
	Blob<int> ia2 = { 0,1,2,3,4 };  //��5��Ԫ�ص�Blob<int>
									//�������������ǵ�Blobģ��ʵ������һ����ʱ��������дBlobģ�壬��ģ�����T��ÿ��ʵ���滻Ϊ������ģ��ʵ�Σ��ڱ�������int


									//������ָ����ÿһ��Ԫ�����ͣ�������������һ����ͬ����
	Blob<string> names;     //����string��Blob
	Blob<double> prices;    //��ͬ��Ԫ������

							//Ĭ������£�һ����ģ��ĳ�Ա����ֻ�е������õ���ʱ�Ž���ʵ����
							//ʵ����Blob<int>�ͽ���initializer_list<int>�Ĺ��캯��
	Blob<int> squares = { 0,1,2,3,4,5,6,7,8,9 };
	//ʵ����Blob<int>::size()const
	for (size_t i = 0; i != squares.size(); ++i)
	{
		squares[i] = i*i;  //ʵ����Blob<int>::operator[](size_t)
	}

	Blob<int> v1 = { 1,2,3 };
	Blob<int> v2 = { 1,2,3 };
	cout << (v1 == v2) << endl;
	cout << (v1 < v2) << endl;

	BlobPtr<int> it = v1.begin(),ib;
	for (; it != v1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	it = v1.begin();
	for (; it < v1.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	it = v1.begin();
	ib = ++it;
	it = v1.begin();
	Blob<char> vc = { 'h','e' };
	BlobPtr<char> ic = vc.begin();
	//cout << (it < ic) << endl;  it��ic��ʵ�����������Ͳ�һ�£����ܱȽ�
	cout << (it < ib) << endl;

	vector<int> v24 = { 1,2,3,4,5,6 };
	Blob<int> b24(v24.begin(), v24.end());
	it = b24.begin();
	for (; it < b24.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	system("pause");
	return 0; 
}