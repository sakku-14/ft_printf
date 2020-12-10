/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:49:10 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/10 09:59:08 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_print_str_sub(t_flag **flag, char *str)
{
	if ((*flag)->minfield > (*flag)->vadigit)
	{
		if ((*flag)->negative)
		{
			(*flag)->ret += write(1, str, (*flag)->vadigit);
			while (((*flag)->minfield)-- > (*flag)->vadigit)
				(*flag)->ret += write(1, " ", 1);
		}
		else if ((*flag)->zero)
		{
			while (((*flag)->minfield)-- > (*flag)->vadigit)
				(*flag)->ret += write(1, "0", 1);
			(*flag)->ret += write(1, str, (*flag)->vadigit);
		}
		else
		{
			while (((*flag)->minfield)-- > (*flag)->vadigit)
				(*flag)->ret += write(1, " ", 1);
			(*flag)->ret += write(1, str, (*flag)->vadigit);
		}
	}
	else
		(*flag)->ret += write(1, str, (*flag)->vadigit);
}

void	pf_pack_null(char **str)
{
	*str = "(null)";
}

void	pf_print_str(t_flag **flag)
{
	char *str;

	str = va_arg((*flag)->ap, char *);
	if (!str)
		pf_pack_null(&str);
	if ((*flag)->vadigit == -1 || (*flag)->vadigit > (ssize_t)ft_strlen(str))
		(*flag)->vadigit = (ssize_t)ft_strlen(str);
	pf_print_str_sub(flag, str);
}
