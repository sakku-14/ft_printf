/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:43:03 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/02 16:43:15 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_error_free_flag(t_flag **flag)
{
	if (flag)
	{
		free(*flag);
		*flag = NULL;
	}
	return (-1);
}

void ft_last_free_flag(t_flag **flag)
{
	if (flag)
	{
		free(*flag);
		*flag = NULL;
	}
}
