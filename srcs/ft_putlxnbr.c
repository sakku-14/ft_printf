/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlxnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:52:46 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/07 14:11:47 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putlxnbr(unsigned int nbr, t_flag **flag)
{
	if (nbr >= 16)
	{
		ft_putlxnbr(nbr / 16, flag);
		ft_putlxnbr(nbr % 16, flag);
	}
	else if (!((*flag)->vadigit == 0))
		ft_putchar("0123456789ABCDEF"[nbr], flag);
}
