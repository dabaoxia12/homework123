#include<iostream>
#include<iomanip>
#include<set>
using namespace std;
//������ʼ����
void Array(double arr[],int s)
{

	cout << "�������������飺" << endl;
	for (int i = 0; i < s; i++)
	{
		double temp = 0;
		cin >> temp;
		arr[i] = temp;
	}
}
int main()
{
	double res = 0;
	int s = 0;
	cout << "���ô�С��" << endl;
	cin >> s;
	double arr[50];
	Array(arr,s);
	multiset<double, greater<double> >  big;     //���

	multiset<double, less<double> > smo;           //С��

	//���ν���������С��
	double key = arr[0];          //��ĳ������Ϊ��ǰ��λ��
	for (int i = 1; i < s; i++)
	{
			if (arr[i] > key)       //�����key�� �����С��
				smo.insert(arr[i]);
			else
				big.insert(arr[i]);
		if ( smo.size() == big.size() - 2)                 //�����ѱ�С�Ѷ�2  ��key����С�� ����ѵĶ�������Ϊkey
		{
			multiset<double, greater<double>>::iterator B = big.begin();
			smo.insert(key);
			key = *B;
			big.erase(big.begin());
		}
		else if ( big.size() == smo.size() - 2)
		{
			multiset<double, less<double>>::iterator S = smo.begin();
			big.insert(key);
			key = *S;
			smo.erase(smo.begin());
		}
	}
	if (big.size() == smo.size()) {              // �����С�Ѵ�С��� ��keyΪ��λ��
		cout << "��λ��Ϊ��" << key << endl;
		return 0;
	}
	else if (big.size() > smo.size())
	{
		multiset<double, greater<double>>::iterator B = big.begin();

		 res = (key + *B)/2;
	}
	else
	{
		multiset<double, less<double>>::iterator S = smo.begin();
		 res = (key + *S) / 2;
	}

	cout << "��λ��Ϊ��" << fixed<<setprecision(2)<< res << endl;
	return 0;
}
