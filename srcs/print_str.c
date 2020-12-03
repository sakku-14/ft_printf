/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:49:10 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/03 12:39:24 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void pf_print_str_sub(t_flag **flag, char *str)
{
	if ((*flag)->minField > (*flag)->vaDigit)
	{
		if ((*flag)->negative)
		{
			(*flag)->ret += write(1, str, (*flag)->vaDigit);
			while (((*flag)->minField)-- > (*flag)->vaDigit)
				(*flag)->ret += write(1, " ", 1);
		}
		else if ((*flag)->zero)
		{
			while (((*flag)->minField)-- > (*flag)->vaDigit)
				(*flag)->ret += write(1, "0", 1);
			(*flag)->ret += write(1, str, (*flag)->vaDigit);
		}
		else
		{
			while (((*flag)->minField)-- > (*flag)->vaDigit)
				(*flag)->ret += write(1, " ", 1);
			(*flag)->ret += write(1, str, (*flag)->vaDigit);
		}
	}
	else
		(*flag)->ret += write(1, str, (*flag)->vaDigit);
}

void pf_pack_null(char **str)
{
	*str = "(null)";
}

void pf_print_str(t_flag **flag)
{
	char *str;

	str = va_arg((*flag)->ap, char *);
	if (!str)
		pf_pack_null(&str);
	if ((*flag)->vaDigit == -1 || (*flag)->vaDigit > (int)ft_strlen(str))
		(*flag)->vaDigit = (int)ft_strlen(str);
//	if ((*flag)->vaDigit == -1 || (*flag)->vaDigit > ft_strlen(str))
//		(*flag)->vaDigit = ft_strlen(str);
	pf_print_str_sub(flag, str);
}
