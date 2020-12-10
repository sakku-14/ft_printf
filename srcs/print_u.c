/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:49:16 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/10 09:49:51 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_print_usnum_pos(t_flag **flag, int digit, unsigned int num)
{
	if ((*flag)->negative)
	{
		pf_print_zero(flag, digit);
		ft_putusnbr(num, flag);
		pf_print_space(flag);
	}
	else if ((*flag)->zero)
	{
		if ((*flag)->zero_signal == true)
			(*flag)->vadigit = (*flag)->minfield;
		else
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

void	pf_print_usnum(t_flag **flag)
{
	unsigned int	num;
	int				digit;

	num = va_arg((*flag)->ap, unsigned int);
	digit = pf_check_usdigit(num);
	if ((*flag)->zero == true && (*flag)->vadigit == -1)
		(*flag)->zero_signal = true;
	if ((*flag)->minfield < (*flag)->vadigit)
		(*flag)->minfield = (*flag)->vadigit;
	if ((*flag)->vadigit < digit)
		if (!((*flag)->vadigit == 0) || num != 0)
			(*flag)->vadigit = digit;
	if ((*flag)->minfield >= digit)
		pf_print_usnum_pos(flag, digit, num);
	else
		ft_putusnbr(num, flag);
}
