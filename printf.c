#include <stdio.h>

int main()
{
	printf("-----------%%c--------------\n");
	char c = 'a';
	printf("%-10s[%c]\n", "[c]", c);
	printf("%-10s[%4c]\n", "[4c]", c);
	printf("%-10s[%04c]\n", "[04c]", c);
	printf("%-10s[%-4c]\n", "[-4c]", c);
	printf("%-10s[%6.4c]\n", "[6.4c]", c);
	printf("%-10s[%06.4c]\n", "[06.4c]", c);
	printf("%-10s[%-6.4c]\n", "[-6.4c]", c);
	printf("%-10s[%-06.4c]\n", "[-06.4c]", c);
	printf("%-10s[%*c]\n", "[*c]", 4, c);
	printf("%-10s[%*.*c]\n", "[*.*c]", 6, 4, c);
	printf("-----------%%s--------------\n");
	char *s = "aaaaa";
}
