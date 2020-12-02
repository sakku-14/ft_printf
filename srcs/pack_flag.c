/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:45:54 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/02 16:46:06 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pf_pack_flag(t_flag **flag)
{
	(*flag)->fmt++;
	while (*(*flag)->fmt)
	{
		if (*(*flag)->fmt == '-')
			(*flag)->negative = true;
		else if (*(*flag)->fmt == '0')
			(*flag)->zero = true;
		else if (*(*flag)->fmt == '*')
			pf_pack_asta(flag);
		else if (*(*flag)->fmt >= '1' && *(*flag)->fmt <= '9')
			if (!(pf_pack_minf(flag)))
				break ;
		if (*(*flag)->fmt == '.')
		{
			pf_pack_asta(flag);
			if (!(pf_pack_vad(flag)))
				break ;
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
}
