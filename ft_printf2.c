#include "ft_printf.h"
#include <stdint.h>

void pf_initflag(t_flag **flag)
{
	(*flag)->negative = false;
	(*flag)->zero = false;
	(*flag)->minField = -1;
	(*flag)->dot = false;
	(*flag)->vaDigit = -1;
	ft_bzero(&(*flag)->conversion, sizeof(char));
}

void pf_pack_num(t_flag **flag, const char **fmt, va_list *ap)
{
	int *tmp;

	if ((*flag)->dot == false)
		tmp = &(*flag)->minField;
	else
		tmp = &(*flag)->vaDigit;
	*tmp = 0;
	while (**fmt && **fmt >= '0' && **fmt <= '9')
	{
		*tmp *= 10;
		*tmp += **fmt - '0';
		(*fmt)++;
	}
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
		{
			pf_pack_num(flag, fmt, ap);
			if (!**fmt)
				break ;
		}
		if (**fmt == '.')
			(*flag)->dot = true;
		if (**fmt == 'c' || **fmt == 's' || **fmt == 'p' || **fmt == 'd' ||
			**fmt == 'i' || **fmt == 'u' || **fmt == 'x' || **fmt == 'X')
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
	long adress;

	adress = (long)va_arg(*ap, void *);
	ft_putxnbr_fd(adress, 1);
}

int pf_switch(const char **fmt, va_list *ap)
{
	t_flag *flag;
	if (!(flag = malloc(sizeof(t_flag))))
		return (-1);
	pf_initflag(&flag);
	pf_pack_flag(&flag, fmt, ap);
//	printf("\nneg:%d\nzero:%d\nminField:%d\ndot:%d\nvaDigit:%d\nconversion:%c\n", (*flag).negative, (*flag).zero, (*flag).minField, (*flag).dot, (*flag).vaDigit, (*flag).conversion);
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
	count = ft_printf("u:%u\nc:%c\ns:%s\nd:%d\ni:%i\nx:%x\nX:%X\np:0x10%p\n", 4294967295, '3', "aaa", 100, 999, 555, 555, str);
	printf("p:%p\n", str);
	printf("\n%d\n", count);
}
