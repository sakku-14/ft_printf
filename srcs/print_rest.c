/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:49:00 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/10 09:53:23 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pf_print_zero(t_flag **flag, int digit)
{
	int counter;

	counter = 0;
	while (counter++ < (*flag)->vadigit - digit)
		(*flag)->ret += write(1, "0", 1);
}

void	pf_print_space(t_flag **flag)
{
	int counter;

	counter = 0;
	while (counter++ < (*flag)->minfield - (*flag)->vadigit)
		(*flag)->ret += write(1, " ", 1);
}
