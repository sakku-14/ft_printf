/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:47:29 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/10 09:48:08 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_print_onechar(t_flag **flag, int c)
{
	if ((*flag)->minfield > 1)
	{
		if ((*flag)->negative)
		{
			(*flag)->ret += write(1, &c, 1);
			while (--((*flag)->minfield))
				(*flag)->ret += write(1, " ", 1);
		}
		else if ((*flag)->zero)
		{
			while (--((*flag)->minfield))
				(*flag)->ret += write(1, "0", 1);
			(*flag)->ret += write(1, &c, 1);
		}
		else
		{
			while (--((*flag)->minfield))
				(*flag)->ret += write(1, " ", 1);
			(*flag)->ret += write(1, &c, 1);
		}
	}
	else
		(*flag)->ret += write(1, &c, 1);
}

void	pf_print_char(t_flag **flag)
{
	int c;

	c = va_arg((*flag)->ap, int);
	pf_print_onechar(flag, c);
}
