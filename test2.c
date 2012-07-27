#include <stdio.h>
#include <string.h>

int main()
{
	char str[10] = "hello";
	char  a = 0x28;
	printf("%c\n", str[0] & a);
	return 0;

}	
