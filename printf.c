#include <stdio.h>

int main()
{
	/*
	printf("-----------%%c--------------\n");
	int c = 'a';
	printf("%-10s[%c]\n", "[c]", c);
	printf("%-10s[%4c]\n", "[4c]", c);
	printf("%-10s[%04c]\n", "[04c]", c);
	printf("%-10s[%-4c]\n", "[-4c]", c);
	printf("%-10s[%.4c]\n", "[.4c]", c);
	printf("%-10s[%6.4c]\n", "[6.4c]", c);
	printf("%-10s[%6.-4c]\n", "[6.-4c]", c);//!!!!!
	printf("%-10s[%6.-4.-5c]\n", "[6.-4.-5c]", c);//!!!!!
	printf("%-10s[%6.0004c]\n", "[6.0004c]", c);//!!!!!
	printf("%-10s[%6.4*c]\n", "[6.4*c]", 3, c);
	printf("%-10s[%06.4c]\n", "[06.4c]", c);
	printf("%-10s[%-6.4c]\n", "[-6.4c]", c);
	printf("%-10s[%-06.4c]\n", "[-06.4c]", c);
	printf("%-10s[%*c]\n", "[*c]", 4, c);
	printf("%-10s[%*.*c]\n", "[*.*c]", 6, 4, c);
	printf("%-10s[%.-4.5c]\n", "[.-4.5c]", c);
	printf("%-10s[%-4.5c]\n", "[-4.5c]", c);
*/

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
	printf("%-10s[%5.4s]\n", "[5.4s]", s);
	printf("%-10s[%.-5.4s]\n", "[.-5.4s]", s);
	printf("%-10s[%-5.4s]\n", "[-5.4s]", s);
	printf("%-10s[%.0-5.4s]\n", "[.0-5.4s]", s);
	printf("%-10s[%.05.4s]\n", "[.05.4s]", s);
	printf("%-10s[%.-05.4s]\n", "[.-05.4s]", s);
	printf("%-10s[%.-t5.4s]\n", "[.-t5.4s]", s);
	printf("%-10s[%0.t5.4s]\n", "[0.t5.4s]", s);
	printf("%-10s[%07.t6.4s]\n", "[07.t6.4s]", s);
	printf("%-10s[%07.6.4s]\n", "[07.6.4s]", s);

	/*
	printf("-----------%%p--------------\n");
	char *p = s;
	printf("%-10s[%p]\n", "[p]", p);
	printf("%-10s[%15p]\n", "[15p]", p);
	printf("%-10s[%015p]\n", "[015p]", p);
	printf("%-10s[%-15p]\n", "[-15p]", p);
	printf("%-10s[%.15p]\n", "[.15p]", p);
	printf("%-10s[%13.15p]\n", "[13.15p]", p);
	printf("%-10s[%020.15p]\n", "[020.15p]", p);
	printf("%-10s[%-20.15p]\n", "[-20.15p]", p);
	printf("%-10s[%-020.15p]\n", "[-020.15p]", p);
	printf("%-10s[%*p]\n", "[*p]", 15, p);
	printf("%-10s[%*.*p]\n", "[*.*p]", 20, 15, p);

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
	printf("%-10s[%*.*d]\n\n", "[*.*d]", 6, 4, d);
	d = -123;
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

	printf("-----------%%u--------------\n");
	unsigned int u = 123;
	printf("%-10s[%u]\n", "[u]", u);
	printf("%-10s[%4u]\n", "[4u]", u);
	printf("%-10s[%04u]\n", "[04u]", u);
	printf("%-10s[%-4u]\n", "[-4u]", u);
	printf("%-10s[%.4u]\n", "[.4u]", u);
	printf("%-10s[%6.4u]\n", "[6.4u]", u);
	printf("%-10s[%06.4u]\n", "[06.4u]", u);
	printf("%-10s[%-6.4u]\n", "[-6.4u]", u);
	printf("%-10s[%-06.4u]\n", "[-06.4u]", u);
	printf("%-10s[%*u]\n", "[*u]", 4, u);
	printf("%-10s[%*.*u]\n\n", "[*.*u]", 6, 4, u);

	printf("-----------%%x--------------\n");
	unsigned int x = 123;
	printf("%-10s[%x]\n", "[x]", x);
	printf("%-10s[%4x]\n", "[4x]", x);
	printf("%-10s[%04x]\n", "[04x]", x);
	printf("%-10s[%-4x]\n", "[-4x]", x);
	printf("%-10s[%.4x]\n", "[.4x]", x);
	printf("%-10s[%6.4x]\n", "[6.4x]", x);
	printf("%-10s[%06.4x]\n", "[06.4x]", x);
	printf("%-10s[%-6.4x]\n", "[-6.4x]", x);
	printf("%-10s[%-06.4x]\n", "[-06.4x]", x);
	printf("%-10s[%*x]\n", "[*x]", 4, x);
	printf("%-10s[%*.*x]\n\n", "[*.*x]", 6, 4, x);

	printf("-----------%%X--------------\n");
	unsigned int X = 123;
	printf("%-10s[%X]\n", "[X]", X);
	printf("%-10s[%4X]\n", "[4X]", X);
	printf("%-10s[%04X]\n", "[04X]", X);
	printf("%-10s[%-4X]\n", "[-4X]", X);
	printf("%-10s[%.4X]\n", "[.4X]", X);
	printf("%-10s[%6.4X]\n", "[6.4X]", X);
	printf("%-10s[%06.4X]\n", "[06.4X]", X);
	printf("%-10s[%-6.4X]\n", "[-6.4X]", X);
	printf("%-10s[%-06.4X]\n", "[-06.4X]", X);
	printf("%-10s[%*X]\n", "[*X]", 4, X);
	printf("%-10s[%*.*X]\n\n", "[*.*X]", 6, 4, X);
*/
}
