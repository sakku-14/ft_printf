/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:52:46 by ysakuma           #+#    #+#             */
/*   Updated: 2020/11/25 10:34:26 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putadnbr_fd(uintptr_t nbr, int fd)
{
	if (nbr >= 16)
	{
		ft_putadnbr_fd(nbr / 16, fd);
		ft_putadnbr_fd(nbr % 16, fd);
	}
	else
		ft_putchar_fd("0123456789abcdef"[nbr], fd);
}
