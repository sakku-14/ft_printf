/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putusnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:52:46 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/07 14:15:00 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putusnbr(unsigned int nbr, t_flag **flag)
{
	if (nbr >= 10)
	{
		ft_putusnbr(nbr / 10, flag);
		ft_putusnbr(nbr % 10, flag);
	}
	else if (!((*flag)->vaDigit == 0))
		ft_putchar(nbr + '0', flag);
}
