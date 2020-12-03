/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysakuma <ysakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:45:35 by ysakuma           #+#    #+#             */
/*   Updated: 2020/12/03 13:09:44 by ysakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int main()
{
	int d = -777;
	int i = 666;
	int count= 0;
	unsigned int u = 555;
	unsigned int x = 444;
	unsigned int X = 333;
	char *str = "aaa";
	char c = 'a';

//---------\0--------------
	printf("\n-------------null-------------\n");
	count = ft_printf("%s", "\0");
	printf("\n%d", count);
	count = printf("%s", "\0");
	printf("\n%d", count);

//---------asta------------
	printf("\n-------------asta-------------\n");
	count = ft_printf("[%10.5d]", i);
	count = ft_printf("[%*.*d]", 10, 5, i);
	printf("\n%d\n", count);
	count = printf("[%10.5d]", i);
	count = printf("[%*.*d]", 10, 5, i);
	printf("\n%d\n", count);

	count = ft_printf("[%-10.5d]", i);
	count = ft_printf("[%*.*d]", -10, 5, i);
	printf("\n%d\n", count);
	count = printf("[%-10.5d]", i);
	count = printf("[%*.*d]", -10, 5, i);
	printf("\n%d\n", count);

	count = ft_printf("[%10.-5d]", i);
	count = ft_printf("[%*.*d]", 10, -5, i);
	printf("\n%d\n", count);
//	count = printf("[%10.-5d]", i);
//	count = printf("[%*.*d]", 10, -5, i);
//	printf("\n%d\n", count);

	count = ft_printf("[%10.5s]", str);
	count = ft_printf("[%*.*s]", 10, 5, str);
	printf("\n%d\n", count);
	count = printf("[%10.5s]", str);
	count = printf("[%*.*s]", 10, 5, str);
	printf("\n%d\n", count);
//---------error-----------
	count = ft_printf(NULL);
	ft_printf("%d\n", count);
//---------%d-----------
	printf("------------d-----------\n");
	count = ft_printf("[%d]", d);
	printf("-->%d\n", count);
	count = printf("[%d]", d);
	printf("-->%d\n", count);
	count = ft_printf("[%7d]", d);
	printf("-->%d\n", count);
	count = printf("[%7d]", d);
	printf("-->%d\n", count);
	count = ft_printf("[%2.10d]", d);
	printf("-->%d\n", count);
	count = printf("[%2.10d]", d);
	printf("-->%d\n", count);
	count = ft_printf("[%10.1d]", d);
	printf("-->%d\n", count);
	count = printf("[%10.1d]", d);
	printf("-->%d\n", count);
	count = ft_printf("[%d]", -14);
	printf("-->%d\n", count);
	count = printf("[%d]", -14);
	printf("-->%d\n", count);
	count = ft_printf("[%7d]", -14);
	printf("-->%d\n", count);
	count = printf("[%7d]", -14);
	printf("-->%d\n", count);
//-----------%p-------------
	printf("\n-------------p-------------\n");
	count = ft_printf("[%20.15p]", str);
	printf("-->%d\n", count);
//	count = printf("[%20.15p]", str);
//	printf("-->%d\n", count);
	count = ft_printf("[%2.15p]", str);
	printf("-->%d\n", count);
//	count = printf("[%2.15p]", str);
//	printf("-->%d\n", count);
	count = ft_printf("[%20.3p]", str);
	printf("-->%d\n", count);
//	count = printf("[%20.3p]", str);
//	printf("-->%d\n", count);

//-----------%u-------------
	printf("\n-------------u-------------\n");
	count = ft_printf("[%10.5d]", u);
	printf("-->%u\n", count);
	count = printf("[%10.5d]", u);
	printf("-->%u\n", count);
	count = ft_printf("[%2.10d]", u);
	printf("-->%u\n", count);
	count = printf("[%2.10d]", u);
	printf("-->%u\n", count);
	count = ft_printf("[%10.1d]", u);
	printf("-->%u\n", count);
	count = printf("[%10.1d]", u);
	printf("-->%u\n", count);
//-----------%x-------------
	printf("\n-------------x-------------\n");
	count = ft_printf("[%10.5x]", x);
	printf("-->%d\n", count);
	count = printf("[%10.5x]", x);
	printf("-->%d\n", count);
	count = ft_printf("[%2.10x]", x);
	printf("-->%d\n", count);
	count = printf("[%2.10x]", x);
	printf("-->%d\n", count);
	count = ft_printf("[%10.1x]", x);
	printf("-->%d\n", count);
	count = printf("[%10.1x]", x);
	printf("-->%d\n", count);
//-----------%X-------------
	printf("\n-------------X-------------\n");
	count = ft_printf("[%10.5X]", X);
	printf("-->%d\n", count);
	count = printf("[%10.5X]", X);
	printf("-->%d\n", count);
	count = ft_printf("[%2.10X]", X);
	printf("-->%d\n", count);
	count = printf("[%2.10X]", X);
	printf("-->%d\n", count);
	count = ft_printf("[%10.1X]", X);
	printf("-->%d\n", count);
	count = printf("[%10.1X]", X);
	printf("-->%d\n", count);
//-----------%s-------------
	printf("\n-------------s-------------\n");
	count = ft_printf("[%20.15s]", str);
	printf("-->%d\n", count);
	count = printf("[%20.15s]", str);
	printf("-->%d\n", count);
	count = ft_printf("[%2.15s]", str);
	printf("-->%d\n", count);
	count = printf("[%2.15s]", str);
	printf("-->%d\n", count);
	count = ft_printf("[%20.3s]", str);
	printf("-->%d\n", count);
	count = printf("[%20.3s]", str);
	printf("-->%d\n", count);
//-----------%c-------------
	printf("\n-------------c-------------\n");
	count = ft_printf("[%20.15c]", c);
	printf("-->%d\n", count);
//	count = printf("[%20.15c]", c);
//	printf("-->%d\n", count);
	count = ft_printf("[%2.15c]", c);
	printf("-->%d\n", count);
//	count = printf("[%2.15c]", c);
//	printf("-->%d\n", count);
	count = ft_printf("[%20.3c]", c);
	printf("-->%d\n", count);
//	count = printf("[%20.3c]", c);
//	printf("-->%d\n", count);
//-----------%%-------------
	printf("\n-------------percent-------------\n");
	count = ft_printf("[%20.15%]");
	printf("-->%d\n", count);
	count = printf("[%20.15%]");
	printf("-->%d\n", count);
	count = ft_printf("[%2.15%]");
	printf("-->%d\n", count);
	count = printf("[%2.15%]");
	printf("-->%d\n", count);
	count = ft_printf("[%20.3%]");
	printf("-->%d\n", count);
	count = printf("[%20.3%]");
	printf("-->%d\n", count);

}
