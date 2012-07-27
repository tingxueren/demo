#include <iostream>
using namespace std;

int count = 0;

void move(int i, char m, char n)
{
	cout << "Move " << i << " From " << m << " to " << n << endl;
	++count;
}	

void hanoi(int n, char i, char j, char k)
{
	if (n > 0)
		{
			hanoi(n-1, i, k, j);
			move(n, i, j);
			hanoi(n-1, k, j, i);
		
		}	
			
}	

int main()
{
	int disk;
	cout << "input number of disk: " ;
	cin >> disk;
	hanoi(disk, 'a', 'b', 'c');
	cout << "steps: " << count << endl;
	return 0;

}

