#include<iostream>    //Ԥ���� 
#include<iomanip>
#include<set>
using namespace std;    //���ÿռ� 
//������ʼ����
void Array(double arr[],int s)
{

	cout << "�������������飺" << endl;   
	for (int i = 0; i < s; i++)        //�������� 
	{
		double temp = 0;    //temp���� 
		cin >> temp;
		arr[i] = temp;
	}
}
int main()    //���������� 
{
	double res = 0;   //��ʼֵΪ0 
	int k = 0;
	int s = 0;
	cout << "���ô�С��" << endl;
	cin >> s;          //����S 
	double arr[50];     //�����±�50 
	Array(arr, s);
	multiset<int, greater<<int>>p;  
	for (int i = 0; i < s; i++)     //������� 
	{
		p.insert(arr[i]);
	}
	cout << "����kֵ��" << endl;
	cin >> k;
	if (k > p.size())                //�ж�K
	{
		cout << "�����д���" << endl;
	}
	else
	{
		while (k>=1)          //��ǰ��ǰK�����ı�׼ 
		{
			multiset<int, greater<int>>::iterator P=p.begin();
			int temp = 0;
			temp = *P;
			cout << temp << "  ";
			p.erase(p.begin());
			k--;
		}
	}
	return 0;   //������ 
}
