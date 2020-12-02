/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:42:27 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/02 16:42:56 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int pf_check_digit(int num)
{
	int dret;

	dret = 0;
	if (num > 0)
	{
		while (num > 1)
		{
			num /= 10;
			dret++;
		}
	}
	else
	{
		while (num < -1)
		{
			num /= 10;
			dret ++;
		}
	}
	return (dret);
}

int pf_check_usdigit(unsigned int num)
{
	int dret;

	dret = 0;
	while (num >= 1)
	{
		num /= 10;
		dret++;
	}
	return (dret);
}

int pf_check_xdigit(unsigned int num)
{
	int count;

	count = 0;
	while (num >= 1)
	{
		num /= 16;
		count++;
	}
	return (count);
}

int pf_check_adddigit(uintptr_t address)
{
	int count;

	count = 0;
	while (address >= 1)
	{
		address /= 16;
		count++;
	}
	return (count);
}
