#include <stdio.h>

int main()
{
	printf("-----------%%c--------------\n");
	char c = 'a';
	printf("%-10s[%c]\n", "[c]", c);
	printf("%-10s[%4c]\n", "[4c]", c);
	printf("%-10s[%04c]\n", "[04c]", c);
	printf("%-10s[%-4c]\n", "[-4c]", c);
	printf("%-10s[%.4c]\n", "[.4c]", c);
	printf("%-10s[%6.4c]\n", "[6.4c]", c);
	printf("%-10s[%06.4c]\n", "[06.4c]", c);
	printf("%-10s[%-6.4c]\n", "[-6.4c]", c);
	printf("%-10s[%-06.4c]\n", "[-06.4c]", c);
	printf("%-10s[%*c]\n", "[*c]", 4, c);
	printf("%-10s[%*.*c]\n", "[*.*c]", 6, 4, c);
	printf("-----------%%s--------------\n");
	char *s = "aaaaa";
	printf("%-10s[%s]\n", "[s]", s);
	printf("%-10s[%4s]\n", "[4s]", s);
	printf("%-10s[%04s]\n", "[04s]", s);
	printf("%-10s[%-4s]\n", "[-4s]", s);
	printf("%-10s[%.4s]\n", "[.4s]", s);
	printf("%-10s[%6.4s]\n", "[6.4s]", s);
	printf("%-10s[%06.4s]\n", "[06.4s]", s);
	printf("%-10s[%-6.4s]\n", "[-6.4s]", s);
	printf("%-10s[%-06.4s]\n", "[-06.4s]", s);
	printf("%-10s[%*s]\n", "[*s]", 4, s);
	printf("%-10s[%*.*s]\n", "[*.*s]", 6, 4, s);
	printf("-----------%%p--------------\n");
	char *p = s;
	printf("%-10s[%p]\n", "[p]", p);
	printf("%-10s[%4p]\n", "[4p]", p);
	printf("%-10s[%04p]\n", "[04p]", p);
	printf("%-10s[%-4p]\n", "[-4p]", p);
	printf("%-10s[%.4p]\n", "[.4p]", p);
	printf("%-10s[%6.4p]\n", "[6.4p]", p);
	printf("%-10s[%06.4p]\n", "[06.4p]", p);
	printf("%-10s[%-6.4p]\n", "[-6.4p]", p);
	printf("%-10s[%-06.4p]\n", "[-06.4p]", p);
	printf("%-10s[%*p]\n", "[*p]", 4, p);
	printf("%-10s[%*.*p]\n", "[*.*p]", 6, 4, p);
	printf("-----------%%d--------------\n");
	int d = 123;
	printf("%-10s[%d]\n", "[d]", d);
	printf("%-10s[%4d]\n", "[4d]", d);
	printf("%-10s[%04d]\n", "[04d]", d);
	printf("%-10s[%-4d]\n", "[-4d]", d);
	printf("%-10s[%.4d]\n", "[.4d]", d);
	printf("%-10s[%6.4d]\n", "[6.4d]", d);
	printf("%-10s[%06.4d]\n", "[06.4d]", d);
	printf("%-10s[%-6.4d]\n", "[-6.4d]", d);
	printf("%-10s[%-06.4d]\n", "[-06.4d]", d);
	printf("%-10s[%*d]\n", "[*d]", 4, d);
	printf("%-10s[%*.*d]\n", "[*.*d]", 6, 4, d);

}
