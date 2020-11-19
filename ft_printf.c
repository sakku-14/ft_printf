#include "ft_printf.h"

void pf_initflag(t_flag flag)
{
	flag.negative = false;
	flag.zero = false;
	flag.minField = -1;
	flag.dot = false;
	flag.vaDigit = -1;
	flag.conversion = '\0';
}

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

void pf_switch(char *fmt, t_flag *flag, va_list *ap)
{
	init_flag(flag);
	flag->fmt = ft_strdup(fmt);
	pf_check_negative(flag);
	pf_check_zero(flag);
	pf_check_minField(flag);
	pf_check_dot(flag);
	pf_check_vaDigit(flag);
	pf_check_conversion(flag);
	if (flag->conversion == 'c')
		pf_print_char(flag, ap);
	else if(flag->conversion == 's')
		pf_print_str(flag, ap);
	else if(flag->conversion == 'p')
		pf_print_adress(flag, ap);
	else if(flag->conversion == 'd' || flag->conversion == 'i')
		pf_print_num(flag, ap);
	else if(flag->conversion == 'u')
		pf_print_unnum(flag, ap);
	else if(flag->conversion == 'x')
		pf_print_xnum(flag, ap);
	else if(flag->conversion == 'X')
		pf_print_Xnum(flag, ap);
	else
		pf_print_erroract(flag, ap);
}

int ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_flag		*flag;

	va_start(ap, fmt);
	pf_switch(&fmt, &flag, &ap);
/*
	if (!fmt)
		n = -1;
	flag.fmt = ft_strdup(fmt);
	while (*(flag.fmt) && n >= 0)
	{
		while (flag.fmt[len] != '%')
			write(1, &(flag.fmt[len++]), 1);
		len++;
		pf_core(&(flag.fmt[len]), &n, &ap);
		len++;
		if (flag.fmt[len] == '\0')
			break ;
	}
	free(flag.fmt);
	flag.fmt = NULL;
*/
	va_end(ap);
	return (flag.ret);
}

int main()
{
	int count = 0;
//	count = ft_printf("str:%s, char:%c, num:%d", "hello", 'W', 14);
	count = printf("hello");
	printf("\n%d\n", count);
}
