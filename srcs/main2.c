#include "../includes/ft_printf.h"

int main()
{
	char *str = "hello";
	ft_printf("%p", NULL);
	printf("\n");
	printf("%p", NULL);
	printf("\n");
	ft_printf("%5.p", NULL);
	printf("\n");
	printf("%5.p", NULL);
	printf("\n");
	ft_printf("%5.p", str);
	printf("\n");
	printf("%5.p", str);
	printf("\n");
}
