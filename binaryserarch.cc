#include <iostream>
using namespace std;

template <class Type>
int BinarySearch(Type a[], const Type& x, int n)
{// 在a[0]到a[n-1]中搜索x, a为排序好的数组
	int left = 0; 
	int right = n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (a[middle] == x) return middle;
		if (a[middle] > x) right = middle - 1;
		else left = middle + 1;

	}
	return -1;
}	

int main()
{
	int a[10], b;
	for (int i = 0; i != 10; i++)
		a[i] = 2 * i;
	b = 5;
	int index = BinarySearch(a, b, 10);
	if (index == -1)
		cout << b << " is not in a " << endl;
	else 
		cout << b << " is " << "a[" << index << "]" << endl;
	return 0;
		
}	
