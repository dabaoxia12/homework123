#include<iostream>    //预处理 
#include<iomanip>
#include<set>
using namespace std;    //设置空间 
//创建初始数组
void Array(double arr[],int s)
{

	cout << "请输入需求数组：" << endl;   
	for (int i = 0; i < s; i++)        //设置数组 
	{
		double temp = 0;    //temp输入 
		cin >> temp;
		arr[i] = temp;
	}
}
int main()    //主函数设置 
{
	double res = 0;   //初始值为0 
	int k = 0;
	int s = 0;
	cout << "设置大小：" << endl;
	cin >> s;          //输入S 
	double arr[50];     //数组下标50 
	Array(arr, s);
	multiset<int, greater<<int>>p;  
	for (int i = 0; i < s; i++)     //数组输出 
	{
		p.insert(arr[i]);
	}
	cout << "输入k值：" << endl;
	cin >> k;
	if (k > p.size())                //判断K
	{
		cout << "输入有错误：" << endl;
	}
	else
	{
		while (k>=1)          //堆前，前K个数的标准 
		{
			multiset<int, greater<int>>::iterator P=p.begin();
			int temp = 0;
			temp = *P;
			cout << temp << "  ";
			p.erase(p.begin());
			k--;
		}
	}
	return 0;   //结束语 
}
