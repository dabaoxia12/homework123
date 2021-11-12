#include<iostream>
#include<iomanip>
#include<set>
using namespace std;
//创建初始数组
void Array(double arr[],int s)
{

	cout << "请输入需求数组：" << endl;
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
	cout << "设置大小：" << endl;
	cin >> s;
	double arr[50];
	Array(arr,s);
	multiset<double, greater<double> >  big;     //大堆

	multiset<double, less<double> > smo;           //小堆

	//依次将数组放入大小堆
	double key = arr[0];          //将某个数设为当前中位数
	for (int i = 1; i < s; i++)
	{
			if (arr[i] > key)       //如果比key大 则放入小堆
				smo.insert(arr[i]);
			else
				big.insert(arr[i]);
		if ( smo.size() == big.size() - 2)                 //如果大堆比小堆多2  将key放入小堆 将大堆的顶部设置为key
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
	if (big.size() == smo.size()) {              // 如果大小堆大小相等 则key为中位数
		cout << "中位数为：" << key << endl;
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

	cout << "中位数为：" << fixed<<setprecision(2)<< res << endl;
	return 0;
}
