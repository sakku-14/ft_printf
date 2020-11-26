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

void pf_print_onechar(t_flag **flag, int c)
{
	if ((*flag)->minField > 1)
	{
		if ((*flag)->negative)
		{
			write(1, &c, 1);
			while (--((*flag)->minField))
				write(1, " ", 1);
		}
		else if ((*flag)->zero)
		{
			while (--((*flag)->minField))
				write(1, "0", 1);
			write(1, &c, 1);
		}
		else
		{
			while (--((*flag)->minField))
				write(1, " ", 1);
			write(1, &c, 1);
		}
	}
	else
		write(1, &c, 1);
}

void pf_print_char(t_flag **flag, va_list *ap)
{
	int c;

	c = va_arg(*ap, int);
	pf_print_onechar(flag, c);
}

void pf_print_str_sub(t_flag **flag, char *str)
{
	if ((*flag)->minField > (*flag)->vaDigit)
	{
		if ((*flag)->negative)
		{
			write(1, str, (*flag)->vaDigit);
			while (((*flag)->minField)-- > (*flag)->vaDigit)
				write(1, " ", 1);
		}
		else if ((*flag)->zero)
		{
			while (((*flag)->minField)-- > (*flag)->vaDigit)
				write(1, "0", 1);
			write(1, str, (*flag)->vaDigit);
		}
		else
		{
			while (((*flag)->minField)-- > (*flag)->vaDigit)
				write(1, " ", 1);
			write(1, str, (*flag)->vaDigit);
		}
	}
	else
		write(1, str, (*flag)->vaDigit);
}

void pf_print_str(t_flag **flag, va_list *ap)
{
	char *str;
	int min;

	str = va_arg(*ap, char *);
	if ((*flag)->vaDigit == -1 || (*flag)->vaDigit > ft_strlen(str))
		(*flag)->vaDigit = ft_strlen(str);
	pf_print_str_sub(flag, str);
}

int pf_check_digit(int num)
{
	int ret;

	ret = 0;
	if (num > 0)
	{
		while (num > 1)
		{
			num /= 10;
			ret++;
		}
	}
	else
	{
		while (num < -1)
		{
			num /= 10;
			ret ++;
		}
	}
	return (ret);
}

void pf_print_zero(t_flag **flag, int digit)
{
	int counter;

	counter = 0;
	while (++counter < (*flag)->vaDigit - digit)
		write(1, "0", 1);
}

void pf_print_space(t_flag **flag)
{
	int counter;

	counter = 0;
	while (counter++ < (*flag)->minField - (*flag)->vaDigit)
		write(1, " ", 1);
}

void pf_print_num_pos(t_flag **flag, int digit, int num)
{

}

void pf_print_num(t_flag **flag, va_list *ap)
{
	int num;
	int counter;
	int digit;

	num = va_arg(*ap, int);
	digit = pf_check_digit(num);
	if ((*flag)->minField < (*flag)->vaDigit)
		(*flag)->minField = (*flag)->vaDigit;
	if ((*flag)->vaDigit < digit)
		(*flag)->vaDigit = digit;
	if ((*flag)->minField > digit)
	{
		if (num >= 0)
		{
			if ((*flag)->negative)
			{
				pf_print_zero(flag, digit);
				ft_putnbr_fd(num, 1);
				pf_print_space(flag);
			}
			else if ((*flag)->zero)
			{
				pf_print_space(flag);
				pf_print_zero(flag, digit);
				ft_putnbr_fd(num, 1);
			}
			else
			{
				pf_print_space(flag);
				ft_putnbr_fd(num, 1);
			}
		}
		else
		{
			((*flag)->minField)--;
			if ((*flag)->negative)
			{
				write(1, "-", 1);
				pf_print_zero(flag, digit);
				ft_putnbr_fd(-num, 1);
				pf_print_space(flag);
			}
			else if ((*flag)->zero)
			{
				pf_print_space(flag);
				write(1, "-", 1);
				pf_print_zero(flag, digit);
				ft_putnbr_fd(-num, 1);
			}
			else
			{
				pf_print_space(flag);
				write(1, "-", 1);
				pf_print_zero(flag, digit);
				ft_putnbr_fd(-num, 1);
			}
		}
	}
	else
	{
		ft_putnbr_fd(num, 1);
	}
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
	pf_print_onechar(flag, '%');
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
		else if (!(pf_switch(&fmt, &ap)))
				return (-1);
	}
	va_end(ap);
	return (1);
}

int main()
{
	int count = 0;
	int num = 123;
	char c = 'x';
	char *str = "aa";
	count = ft_printf("ft_printf->[%-7.5d]\n", num);
	count = printf("printf---->[%-7.5d]\n", num);
//	count = ft_printf("[%-06.4s]\n", str);
//	count = ft_printf("[%%]\n");
//	count = ft_printf("%-5.t3.5s\n", "aaaaa");
//	count = ft_printf("%%", 5);
//	count = ft_printf("----ft_printf----\ntext:hello\nu:%u\nc:%c\ns:%s\nd:%d\ni:%i\nx:%x\nX:%X\np:%p\n", 4294967295, '3', "aaa", 100, 999, 555, 555, str);
	printf("\n%d\n", count);
}
