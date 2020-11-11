#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void ft_print_str(const char **fmt, const char **start, size_t *n)
{
	size_t	len;

	len = 0;
	while (**fmt != '%' && **fmt)
		(*fmt)++;
	write(1, *start, *fmt - *start);
	if (n >= 0)
		n += *fmt - *start;
}

int ft_printf(const char *fmt, ...)
{
	va_list		args;
	size_t		n;
	const char	*start;

	n = 0;
	va_start(args, fmt);
	if (!fmt)
		n = -1;
	while (*fmt && n >= 0)
	{
		if (*fmt != '%')
		{
			start = fmt;
			ft_print_str(&fmt, &start, &n);
		}
		else
		{
			fmt++;
			while (*fmt != 'd')
				fmt++;
			fmt++;
		}
	}
	va_end(args);
	return (n);
}

int main()
{
	ft_printf("hello%5.3dworld", 3);
	return (0);
}
