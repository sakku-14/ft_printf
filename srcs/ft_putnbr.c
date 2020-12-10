/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:52:46 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/07 14:14:44 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(int n, t_flag **flag)
{
	unsigned int nbr;

	if (n < 0)
	{
		nbr = (unsigned int)(-1 * n);
		ft_putchar('-', flag);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, flag);
		ft_putnbr(nbr % 10, flag);
	}
	else if (!((*flag)->vadigit == 0))
		ft_putchar(nbr + '0', flag);
}
