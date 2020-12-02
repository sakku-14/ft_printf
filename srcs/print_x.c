/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:49:22 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/02 16:49:26 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pf_print_xnum_sub(t_flag **flag, int digit, unsigned int num)
{
	if ((*flag)->negative)
	{
		pf_print_zero(flag, digit);
		ft_putxnbr(num, flag);
		pf_print_space(flag);
	}
	else if ((*flag)->zero)
	{
		pf_print_space(flag);
		pf_print_zero(flag, digit);
		ft_putxnbr(num, flag);
	}
	else
	{
		pf_print_space(flag);
		pf_print_zero(flag, digit);
		ft_putxnbr(num, flag);
	}
}

void pf_print_xnum(t_flag **flag)
{
	unsigned int num;
	int digit;

	num = va_arg((*flag)->ap, unsigned int);
	digit = pf_check_xdigit(num);

	if ((*flag)->minField < (*flag)->vaDigit)
		(*flag)->minField = (*flag)->vaDigit;
	if ((*flag)->vaDigit < digit)
		(*flag)->vaDigit = digit;
	if ((*flag)->minField > digit)
		pf_print_xnum_sub(flag, digit, num);
	else
		ft_putxnbr(num, flag);
}
