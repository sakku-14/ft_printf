/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_act.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:49:30 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/10 09:47:31 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pf_switch(t_flag **flag)
{
	pf_initflag(flag);
	if (!(pf_pack_flag(flag)))
		return (0);
	if ((*flag)->minField >= 2147483647 || (*flag)->vaDigit >= 2147483647)
		return (0);
	if ((*flag)->conversion == 'c')
		pf_print_char(flag);
	else if ((*flag)->conversion == 's')
		pf_print_str(flag);
	else if ((*flag)->conversion == 'p')
		pf_print_address(flag);
	else if ((*flag)->conversion == 'd' || (*flag)->conversion == 'i')
		pf_print_num(flag);
	else if ((*flag)->conversion == 'u')
		pf_print_usnum(flag);
	else if ((*flag)->conversion == 'x')
		pf_print_xnum(flag);
	else if ((*flag)->conversion == 'X')
		pf_print_lxnum(flag);
	else if ((*flag)->conversion == '%')
		pf_print_percent(flag);
	return (1);
}
