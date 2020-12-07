/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:47:05 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/06 15:34:31 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void pf_print_add(t_flag **flag, int digit, uintptr_t address)
{
	(*flag)->minField -= 2;
	if ((*flag)->negative)
	{
		(*flag)->ret += write(1, "0x", 2);
		pf_print_zero(flag, digit);
		ft_putadnbr(address, flag);
		pf_print_space(flag);
	}
	else if ((*flag)->zero)
	{
		pf_print_space(flag);
		(*flag)->ret += write(1, "0x", 2);
		pf_print_zero(flag, digit);
		ft_putadnbr(address, flag);
	}
	else
	{
		pf_print_space(flag);
		(*flag)->ret += write(1, "0x", 2);
		pf_print_zero(flag, digit);
		if (!(address == 0 && (*flag)->vaDigit == 0))
			ft_putadnbr(address, flag);
	}
}

void pf_print_address(t_flag **flag)
{
	uintptr_t address;
	int digit;

	address = (uintptr_t)va_arg((*flag)->ap, void *);
	digit = pf_check_adddigit(address);
	if ((*flag)->minField < (*flag)->vaDigit)
		(*flag)->minField = (*flag)->vaDigit;
	if ((*flag)->vaDigit < digit)
		(*flag)->vaDigit = digit;// + 1;
	if ((*flag)->minField > digit)
	{
		if ((*flag)->vaDigit == 1 && address == 0)
			(*flag)->vaDigit = 0;
		pf_print_add(flag, digit, address);
	}
	else
	{
		(*flag)->ret += write(1, "0x", 2);
		if (address != 0)
			ft_putadnbr(address, flag);
		else if ((*flag)->vaDigit == 1)
			{
				(*flag)->ret += write(1, "0", 1);
			}
	}
}
