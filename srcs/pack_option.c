/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:46:37 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/02 16:46:51 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int pf_pack_minf(t_flag **flag)
{
	int *tmp;

	tmp = &(*flag)->minField;
	*tmp = 0;
	while (*(*flag)->fmt && *(*flag)->fmt >= '0' && *(*flag)->fmt <= '9')
	{
		*tmp *= 10;
		*tmp += *(*flag)->fmt - '0';
		((*flag)->fmt)++;
	}
	if (!*(*flag)->fmt)
		return (0);
	return (1);
}

int pf_pack_vad(t_flag **flag)
{
	int *tmp;

	if (*(*flag)->fmt == '*')
		return (1);
	tmp = &(*flag)->vaDigit;
	*tmp = 0;
	((*flag)->fmt)++;
	if (!*(*flag)->fmt)
		return (0);
	if (!(*(*flag)->fmt >= '0' && *(*flag)->fmt <= '9'))
	{
		((*flag)->fmt)--;
		return (1);
	}
	while (*(*flag)->fmt >= '0' && *(*flag)->fmt <= '9')
	{
		*tmp *= 10;
		*tmp += *(*flag)->fmt - '0';
		((*flag)->fmt)++;
	}
	if (!*(*flag)->fmt)
		return (0);
	return (1);
}

void pf_pack_asta(t_flag **flag)
{
	if (*(*flag)->fmt == '.')
	{
		((*flag)->fmt)++;
		if (*(*flag)->fmt && *(*flag)->fmt == '*')
		{
			(*flag)->vaDigit = va_arg((*flag)->ap, int);
			if ((*flag)->vaDigit < 0)
				(*flag)->vaDigit = -1;
		}
		else
			((*flag)->fmt)--;
	}
	else
	{
		(*flag)->minField = va_arg((*flag)->ap, int);
		if ((*flag)->minField < 0)
		{
			(*flag)->negative = true;
			(*flag)->minField *= -1;
		}
	}
}
