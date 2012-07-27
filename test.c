#include <stdio.h>
#include <string.h>


int main()
{
	FILE *f1;
	f1 = fopen("test.txt", "r");
	char s[100], *p;
	
        p = fgets(s, 4, f1);
	printf("%s\n", p);
	printf("%s\n", s);
        p = fgets(s, 8, f1);
	printf("%s\n", p);
	printf("hello, world!\n");

	return 0;
}	
