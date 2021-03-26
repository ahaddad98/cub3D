/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:56:23 by ahaddad           #+#    #+#             */
/*   Updated: 2019/11/08 19:01:37 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(int reslt, int b, int count)
{
	if (count > 19)
	{
		if (b >= 0)
			return (-1);
		else
			return (0);
	}
	return (reslt * b);
}

int			ft_atoi(const char *str)
{
	int		a;
	int		b;
	int		c;
	int		counter;

	a = 0;
	b = 1;
	c = 0;
	counter = 0;
	while (str[a] == ' ' || str[a] == '\f' || str[a] == '\n' || str[a] == '\t'
			|| str[a] == '\r' || str[a] == '\v')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a] == '-')
			b = -1;
		a++;
	}
	while (str[a] != '\0' && str[a] >= '0' && str[a] <= '9')
	{
		c = c * 10 + str[a] - '0';
		a++;
		counter++;
	}
	return (check(c, b, counter));
}
