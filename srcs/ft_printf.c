/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:43:31 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/16 10:27:29 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	t_flag	*flag;
	int		ret;

	if (!(flag = malloc(sizeof(t_flag))))
		return (-1);
	flag->ret = 0;
	if (!fmt)
		return (ft_error_free_flag(&flag));
	va_start(flag->ap, fmt);
	flag->fmt = fmt;
	while (*flag->fmt)
	{
		if (*flag->fmt != '%')
			flag->ret += write(1, flag->fmt++, 1);
		else if (!(pf_switch(&flag)))
			return (ft_error_free_flag(&flag));
	}
	va_end(flag->ap);
	ret = flag->ret;
	ft_last_free_flag(&flag);
	return (ret);
}
