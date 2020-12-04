/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:48:09 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/03 15:42:02 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void pf_print_num_pos(t_flag **flag, int digit, int num)
{
	if ((*flag)->negative)
	{
		pf_print_zero(flag, digit);
		ft_putnbr(num, flag);
		pf_print_space(flag);
	}
	else if ((*flag)->zero == true)
	{
		if ((*flag)->zero_signal == true)
			(*flag)->vaDigit = (*flag)->minField;
		else
			pf_print_space(flag);
		pf_print_zero(flag, digit);
		ft_putnbr(num, flag);
	}
	else
	{
		pf_print_space(flag);
		pf_print_zero(flag, digit);
		ft_putnbr(num, flag);
	}
}

void pf_print_num_neg(t_flag **flag, int digit, int num)
{
	((*flag)->minField)--;
	if ((*flag)->negative)
	{
		(*flag)->ret += write(1, "-", 1);
		pf_print_zero(flag, digit);
		ft_putnbr(-num, flag);
		pf_print_space(flag);
	}
	else if ((*flag)->zero == true)
	{
		if ((*flag)->zero_signal == true)
			(*flag)->vaDigit = (*flag)->minField;
		else
			pf_print_space(flag);
		(*flag)->ret += write(1, "-", 1);
		pf_print_zero(flag, digit);
		ft_putnbr(-num, flag);
	}
	else
	{
		pf_print_space(flag);
		(*flag)->ret += write(1, "-", 1);
		pf_print_zero(flag, digit);
		ft_putnbr(-num, flag);
	}
}

void pf_print_num(t_flag **flag)
{
	int num;
	int digit;

	num = va_arg((*flag)->ap, int);
	digit = pf_check_digit(num);
	if ((*flag)->zero == true && (*flag)->vaDigit == -1)
		(*flag)->zero_signal = true;
	if ((*flag)->minField < (*flag)->vaDigit)
		(*flag)->minField = (*flag)->vaDigit;
	if ((*flag)->vaDigit < digit)
		(*flag)->vaDigit = digit;
	if ((*flag)->minField > digit)
	{
		if (num >= 0)
			pf_print_num_pos(flag, digit, num);
		else
			pf_print_num_neg(flag, digit, num);
	}
	else
	{
		ft_putnbr(num, flag);
	}
}
