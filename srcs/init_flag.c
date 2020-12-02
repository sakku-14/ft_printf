/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:45:21 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/02 16:45:23 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void pf_initflag(t_flag **flag)
{
	(*flag)->negative = false;
	(*flag)->zero = false;
	(*flag)->minField = -1;
	(*flag)->vaDigit = -1;
	ft_bzero(&(*flag)->conversion, sizeof(char));
}
