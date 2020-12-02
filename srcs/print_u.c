/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:49:16 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/02 16:49:19 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pf_print_usnum_pos(t_flag **flag, int digit, unsigned int num)
{
	if ((*flag)->negative)
	{
		pf_print_zero(flag, digit);
		ft_putusnbr(num, flag);
		pf_print_space(flag);
	}
	else if ((*flag)->zero)
	{
		pf_print_space(flag);
		pf_print_zero(flag, digit);
		ft_putusnbr(num, flag);
	}
	else
	{
		pf_print_space(flag);
		pf_print_zero(flag, digit);
		ft_putusnbr(num, flag);
	}
}

void pf_print_usnum(t_flag **flag)
{
	unsigned int num;
	int digit;

	num = va_arg((*flag)->ap, unsigned int);
	digit = pf_check_usdigit(num);
	if ((*flag)->minField < (*flag)->vaDigit)
		(*flag)->minField = (*flag)->vaDigit;
	if ((*flag)->vaDigit < digit)
		(*flag)->vaDigit = digit;
	if ((*flag)->minField > digit)
		pf_print_usnum_pos(flag, digit, num);
	else
		ft_putusnbr(num, flag);
}
