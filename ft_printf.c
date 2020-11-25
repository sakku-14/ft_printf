#include "ft_printf.h"

void pf_initflag(t_flag **flag)
{
	(*flag)->negative = false;
	(*flag)->zero = false;
	(*flag)->minField = -1;
	(*flag)->vaDigit = -1;
	ft_bzero(&(*flag)->conversion, sizeof(char));
}

int pf_pack_minf(t_flag **flag, const char **fmt, va_list *ap)
{
	int *tmp;

	tmp = &(*flag)->minField;
	*tmp = 0;
	while (**fmt && **fmt >= '0' && **fmt <= '9')
	{
		*tmp *= 10;
		*tmp += **fmt - '0';
		(*fmt)++;
	}
	if (!**fmt)
		return (0);
	return (1);
}

int pf_pack_vad(t_flag **flag, const char **fmt, va_list *ap)
{
	int *tmp;

	tmp = &(*flag)->vaDigit;
	*tmp = 0;
	(*fmt)++;
	if (!(**fmt >= '0' && **fmt <= '9'))
	{
		(*fmt)--;
		return (1);
	}
	while (**fmt && **fmt >= '0' && **fmt <= '9')
	{
		*tmp *= 10;
		*tmp += **fmt - '0';
		(*fmt)++;
	}
	if (!**fmt)
		return (0);
	return (1);
}

void pf_pack_flag(t_flag **flag, const char **fmt, va_list *ap)
{
	if (**fmt == '%')
		(*fmt)++;
	while (**fmt)
	{
		if (**fmt == '-')
			(*flag)->negative = true;
		else if (**fmt == '0')
			(*flag)->zero = true;
		else if (**fmt >= '1' && **fmt <= '9')
			if (!(pf_pack_minf(flag, fmt, ap)))
				break ;
		if (**fmt == '.')
			if (!(pf_pack_vad(flag, fmt, ap)))
				break ;
		if (**fmt == 'c' || **fmt == 's' || **fmt == 'p' || **fmt == 'd' ||
			**fmt == 'i' || **fmt == 'u' || **fmt == 'x' || **fmt == 'X' || **fmt == '%')
		{
			(*flag)->conversion = **fmt;
			(*fmt)++;
			break ;
		}
		(*fmt)++;
	}
}

void pf_print_char(t_flag **flag, va_list *ap)
{
	int c;

	c = va_arg(*ap, int);
	write(1, &c, 1);
}

void pf_print_str(t_flag **flag, va_list *ap)
{
	char *str;

	str = va_arg(*ap, char *);
	write(1, str, ft_strlen(str));
}

void pf_print_num(t_flag **flag, va_list *ap)
{
	int num;

	num = va_arg(*ap, int);
	ft_putnbr_fd(num, 1);
}

void pf_print_usnum(t_flag **flag, va_list *ap)
{
	unsigned int num;

	num = va_arg(*ap, unsigned int);
	ft_putusnbr_fd(num, 1);
}

void pf_print_xnum(t_flag **flag, va_list *ap)
{
	unsigned int num;

	num = va_arg(*ap, unsigned int);
	ft_putxnbr_fd(num, 1);
}

void pf_print_lxnum(t_flag **flag, va_list *ap)
{
	unsigned int num;

	num = va_arg(*ap, unsigned int);
	ft_putlxnbr_fd(num, 1);
}

void pf_print_adress(t_flag **flag, va_list *ap)
{
	uintptr_t adress;

	adress = (uintptr_t)va_arg(*ap, void *);
	write(1, "0x", 2);
	ft_putadnbr_fd(adress, 1);
}

void pf_print_percent(t_flag **flag, va_list *ap)
{
	write(1, "%", 1);
}

int pf_switch(const char **fmt, va_list *ap)
{
	t_flag *flag;
	if (!(flag = malloc(sizeof(t_flag))))
		return (-1);
	pf_initflag(&flag);
	pf_pack_flag(&flag, fmt, ap);
//	printf("\nneg:%d\nzero:%d\nminField:%d\nvaDigit:%d\nconversion:%c\n", (*flag).negative, (*flag).zero, (*flag).minField, (*flag).vaDigit, (*flag).conversion);
	if (flag->conversion == 'c')
		pf_print_char(&flag, ap);
	else if(flag->conversion == 's')
		pf_print_str(&flag, ap);
	else if(flag->conversion == 'p')
		pf_print_adress(&flag, ap);
	else if(flag->conversion == 'd' || flag->conversion == 'i')
		pf_print_num(&flag, ap);
	else if(flag->conversion == 'u')
		pf_print_usnum(&flag, ap);
	else if(flag->conversion == 'x')
		pf_print_xnum(&flag, ap);
	else if(flag->conversion == 'X')
		pf_print_lxnum(&flag, ap);
	else if(flag->conversion == '%')
		pf_print_percent(&flag, ap);
/*
	else
		pf_print_erroract(&flag, ap);
*/
	return (1);
}

int ft_printf(const char *fmt, ...)
{
	va_list		ap;

	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt != '%')
			write(1, fmt++, 1);
		else
		{
			if (!(pf_switch(&fmt, &ap)))
				return (-1);
		}
	}
	va_end(ap);
	return (1);
}

int main()
{
	int count = 0;
	char *str = "hello";
//	count = ft_printf("%-5.t3.5s\n", "aaaaa");
//	count = ft_printf("%%", 5);
	count = ft_printf("----ft_printf----\ntext:hello\nu:%u\nc:%c\ns:%s\nd:%d\ni:%i\nx:%x\nX:%X\np:%p\n", 4294967295, '3', "aaa", 100, 999, 555, 555, str);
	printf("\n%d\n", count);
}
