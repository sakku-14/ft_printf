#include "../includes/ft_printf.h"
#include <stdio.h>

int main()
{
	int count = ft_printf("%*d\n", -2147483648, 555);
	printf("%d\n", count);
}
