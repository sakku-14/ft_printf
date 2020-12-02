/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:53:41 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/02 16:44:53 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char *ret_str;
	char *tmp;

	if (!(ret_str = malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	tmp = ret_str;
	while (*s1)
		*ret_str++ = *s1++;
	*ret_str = '\0';
	ret_str = tmp;
	return (ret_str);
}
