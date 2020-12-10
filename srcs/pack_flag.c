/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:45:54 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/10 14:10:23 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pf_check_conversion(t_flag **flag)
{
	if (*(*flag)->fmt == 'c')
		return (1);
	else if (*(*flag)->fmt == 's')
		return (1);
	else if (*(*flag)->fmt == 'p')
		return (1);
	else if (*(*flag)->fmt == 'd')
		return (1);
	else if (*(*flag)->fmt == 'i')
		return (1);
	else if (*(*flag)->fmt == 'u')
		return (1);
	else if (*(*flag)->fmt == 'x')
		return (1);
	else if (*(*flag)->fmt == 'X')
		return (1);
	else if (*(*flag)->fmt == '%')
		return (1);
	else
		return (0);
}

int	pf_pack_after_dot(t_flag **flag)
{
	if (*(*flag)->fmt == '.')
	{
		if (!(pf_pack_asta(flag)))
			return (0);
		if (!(pf_pack_vad(flag)))
			return (0);
	}
	return (1);
}

int	pf_pack_conversion(t_flag **flag)
{
	if (pf_check_conversion(flag))
	{
		(*flag)->conversion = *(*flag)->fmt;
		((*flag)->fmt)++;
		return (0);
	}
	return (1);
}

int	pf_pack_flag(t_flag **flag)
{
	(*flag)->fmt++;
	while (*(*flag)->fmt)
	{
		if (*(*flag)->fmt == ' ')
			(*flag)->ret += write(1, " ", 1);
		if (*(*flag)->fmt == '-')
			(*flag)->negative = true;
		else if (*(*flag)->fmt == '0')
			(*flag)->zero = true;
		else if (*(*flag)->fmt == '*')
		{
			if (!(pf_pack_asta(flag)))
				return (0);
		}
		else if (*(*flag)->fmt >= '1' && *(*flag)->fmt <= '9')
			if (!(pf_pack_minf(flag)))
				return (0);
		if (!(pf_pack_after_dot(flag)))
			return (0);
		if (!(pf_pack_conversion(flag)))
			break ;
		((*flag)->fmt)++;
	}
	return (1);
}
