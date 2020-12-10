/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pack_option.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:46:37 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/10 10:47:04 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pf_pack_minf(t_flag **flag)
{
	ssize_t	*tmp;
	int		counter;

	tmp = &(*flag)->minfield;
	*tmp = 0;
	counter = 0;
	while (*(*flag)->fmt && *(*flag)->fmt >= '0' && *(*flag)->fmt <= '9')
	{
		*tmp *= 10;
		*tmp += *(*flag)->fmt - '0';
		((*flag)->fmt)++;
		if (++counter >= 10 && *tmp > 2147483647)
		{
			(*flag)->ret = -1;
			return (0);
		}
	}
	if (!*(*flag)->fmt)
		return (0);
	return (1);
}

int	pf_pack_vad_sub(t_flag **flag, ssize_t *tmp)
{
	int	counter;

	counter = 0;
	while (*(*flag)->fmt >= '0' && *(*flag)->fmt <= '9')
	{
		*tmp *= 10;
		*tmp += *(*flag)->fmt - '0';
		((*flag)->fmt)++;
		if (++counter >= 10 && *tmp > 2147483647)
		{
			(*flag)->ret = -1;
			return (0);
		}
	}
	return (1);
}

int	pf_pack_vad(t_flag **flag)
{
	ssize_t	*tmp;

	if (*(*flag)->fmt == '*')
		return (1);
	tmp = &(*flag)->vadigit;
	*tmp = 0;
	((*flag)->fmt)++;
	if (!*(*flag)->fmt)
		return (0);
	if (!(*(*flag)->fmt >= '0' && *(*flag)->fmt <= '9'))
	{
		((*flag)->fmt)--;
		return (1);
	}
	if (!(pf_pack_vad_sub(flag, tmp)))
		return (0);
	if (!*(*flag)->fmt)
		return (0);
	return (1);
}
