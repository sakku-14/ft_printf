/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:49:00 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/02 16:49:03 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pf_print_zero(t_flag **flag, int digit)
{
	int counter;

	counter = 0;
	while (counter++ < (*flag)->vaDigit - digit)
		(*flag)->ret += write(1, "0", 1);
}

void pf_print_space(t_flag **flag)
{
	int counter;

	counter = 0;
	while (counter++ < (*flag)->minField - (*flag)->vaDigit)
		(*flag)->ret += write(1, " ", 1);
}
