#include <iostream>
#include <vector>
using namespace std;

template <class T>
// int n 不能写成 int &n, 貌似不是指针类型的不能写成引用,对8而言，8为const int 类型
// 一般要写成const 为了更好的匹配
T max(const int &n, const vector<T>& v)
{
	T m = v[0];
	for (int i = 1; i != n; i++)
		if (m < v[i])
			m = v[i];
	return m;
}	


template <class T>
T min(const int &n, const vector<T>& v)
{
	T m = v[0];
	for (int i = 1; i != n; i++)
		if (m > v[i])
			m = v[i];
	return m;
}	

int main()
{
	vector<int> ivec;
	int num;
        int a = 8; 
	cout << "please enter 8 numebers:" << endl;
	while(cin >> num)
		ivec.push_back(num);
	cout << "The max num is: " << max(a, ivec) << endl;
	cout << "The min num is: " << min(a, ivec) << endl;
	return 0;

}	
