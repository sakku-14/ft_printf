/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:47:57 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/08 13:53:13 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void pf_print_lxnum_sub(t_flag **flag, int digit, unsigned int num)
{
	if ((*flag)->negative)
	{
		pf_print_zero(flag, digit);
		ft_putlxnbr(num, flag);
		pf_print_space(flag);
	}
	else if ((*flag)->zero)
	{
		if ((*flag)->zero_signal == true)
			(*flag)->vaDigit = (*flag)->minField;
		else
			pf_print_space(flag);
		pf_print_zero(flag, digit);
		ft_putlxnbr(num, flag);
	}
	else
	{
		pf_print_space(flag);
		pf_print_zero(flag, digit);
		ft_putlxnbr(num, flag);
	}
}

void pf_print_lxnum(t_flag **flag)
{
	unsigned int num;
	int digit;

	num = va_arg((*flag)->ap, unsigned int);
	digit = pf_check_xdigit(num);

	if ((*flag)->zero == true && (*flag)->vaDigit == -1)
		(*flag)->zero_signal = true;
	if ((*flag)->minField < (*flag)->vaDigit)
		(*flag)->minField = (*flag)->vaDigit;
	if ((*flag)->vaDigit < digit)
		if (!((*flag)->vaDigit == 0) || num != 0)
			(*flag)->vaDigit = digit;
	if ((*flag)->minField >= digit)
		pf_print_lxnum_sub(flag, digit, num);
	else
		ft_putlxnbr(num, flag);
}
