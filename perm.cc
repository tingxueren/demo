#include <iostream>
using namespace std;

template <class Type>
void Perm(Type list[], int k, int m)
{ // 产生list[k:m]的所有序列
	if (k == m)
	{ // 只有一个元素
		for (int i = 0; i <= m; i++)
			cout << list[i];
		cout << endl;
	
	}
	else // 多个元素待排列
	{
		for (int i = k; i <= m; i++)
		{
			Swap(list[k], list[i]);
			Perm(list, k+1, m);
			Swap(list[k], list[i]);

		}
	}	

}	

template <class Type>
inline void Swap(Type &a, Type &b)
{
	Type temp = a; a = b; b = temp;
}	

int main()
{
	int a[5];
	for (int i = 0; i != 5; i++)
		a[i] = i + 1;
	Perm(a, 0, 3);
	return 0;
}	
