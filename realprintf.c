#include <stdio.h>

int main()
{
	char *str = "hello";
	int num = 12345;
	printf("[%10s]\n", str);
	printf("[%d]\n", num);
	printf("[% d]\n", num);
	printf("[%+10d]\n", num);
	printf("[%-10d]\n", num);
}
