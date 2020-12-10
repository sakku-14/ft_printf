/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_option_asta.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 10:39:35 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/10 10:49:47 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_pack_asta_va(t_flag **flag)
{
	int tmp;

	((*flag)->fmt)++;
	if (*(*flag)->fmt && *(*flag)->fmt == '*')
	{
		tmp = va_arg((*flag)->ap, int);
		if (tmp < 0)
			(*flag)->vadigit = -1;
		else
			(*flag)->vadigit = tmp;
	}
	else
		((*flag)->fmt)--;
}

int		pf_pack_asta_min(t_flag **flag)
{
	int tmp;

	tmp = va_arg((*flag)->ap, int);
	if (tmp == 2147483647 || tmp == -2147483648)
		return (0);
	if (tmp < 0)
	{
		(*flag)->negative = true;
		(*flag)->minfield = -1 * tmp;
	}
	else
		(*flag)->minfield = tmp;
	return (1);
}

int		pf_pack_asta(t_flag **flag)
{
	if (*(*flag)->fmt == '.')
		pf_pack_asta_va(flag);
	else if (!(pf_pack_asta_min(flag)))
		return (0);
	return (1);
}
