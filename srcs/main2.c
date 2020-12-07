#include "../includes/ft_printf.h"

int main()
{
	ft_printf("%.0d\n", 0);
	printf("%.0d\n", 0);
	ft_printf("%.0d\n", 100);
	printf("%.0d\n", 100);
	ft_printf("%5.0d\n", 100);
	printf("%5.0d\n", 100);
}
