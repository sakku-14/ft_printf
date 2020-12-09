/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putxnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:52:46 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/07 14:10:22 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putxnbr(unsigned int nbr, t_flag **flag)
{
	if (nbr >= 16)
	{
		ft_putxnbr(nbr / 16, flag);
		ft_putxnbr(nbr % 16, flag);
	}
	else if ((*flag)->vaDigit != 0)
		ft_putchar("0123456789abcdef"[nbr], flag);
}
