#include "../includes/ft_printf.h"

int main()
{
	int count = ft_printf("%99999999999d\n", 555);
	printf("%d\n", count);
}
