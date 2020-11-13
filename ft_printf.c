#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void pf_core(char *fmt_cp, int *n, va_list *ap)
{
	char *str, c;
	int d, len;

	len = 0;
	if (*fmt_cp == 's')
	{
		str = va_arg(*ap, char *);
		write(1, str, strlen(str));
	}
	else if (*fmt_cp == 'd')
	{
		d = va_arg(*ap, int);
		printf("%d", d);
	}
	else if (*fmt_cp == 'c')
	{
		c = va_arg(*ap, int);
		write(1, &c, 1);
	}
}


int ft_printf(const char *fmt, ...)
{
	va_list		ap;
	int n = 0, len = 0;
	char *fmt_cp;

	va_start(ap, fmt);
	if (!fmt)
		n = -1;
	fmt_cp = strdup(fmt);
	while (*fmt && n >= 0)
	{
		while (fmt_cp[len] != '%')
			write(1, &fmt_cp[len++], 1);
		len++;
		pf_core(&fmt_cp[len], &n, &ap);
		len++;
		if (fmt_cp[len] == '\0')
			break ;
	}
	free(fmt_cp);
	va_end(ap);
	return (n);
}

int main()
{
	int count = 0;
	count = ft_printf("str:%s, char:%c, num:%d", "hello", 'W', 14);
	printf("\n%d\n", count);
}
