/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:45:54 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/08 12:13:04 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int pf_pack_flag(t_flag **flag)
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
				return (0) ;
		if (*(*flag)->fmt == '.')
		{
			if (!(pf_pack_asta(flag)))
				return (0);
			if (!(pf_pack_vad(flag)))
				return (0) ;
		}
		if (*(*flag)->fmt == 'c' || *(*flag)->fmt == 's' || *(*flag)->fmt == 'p' || *(*flag)->fmt == 'd' ||
			*(*flag)->fmt == 'i' || *(*flag)->fmt == 'u' || *(*flag)->fmt == 'x' || *(*flag)->fmt == 'X' || *(*flag)->fmt == '%')
		{
			
			(*flag)->conversion = *(*flag)->fmt;
			((*flag)->fmt)++;
			break ;
		}
		((*flag)->fmt)++;
	}
	return (1);
}
