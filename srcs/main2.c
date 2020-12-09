#include "../includes/ft_printf.h"

int main()
{
	int d = 777;
	char *str = "hello";
	unsigned int u = 555;
	ft_printf("%d\n%s\n%u\n", d, str, u);
}
