#include <stdio.h>

int main()
{
	int a = 10;
	int *p = &a;
	int *q;
	q = &a;
	//*q = a;
	printf("%d\t%d\t\n", *p, *q);
	return 0;
}	
