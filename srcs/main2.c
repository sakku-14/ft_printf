#include "../includes/ft_printf.h"

int main()
{
	int count = 0;
	char *str = NULL;
	count = ft_printf("%10s", str);
	ft_printf("\n%d\n", count);
}
