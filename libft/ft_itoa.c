/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 12:52:24 by ahaddad           #+#    #+#             */
/*   Updated: 2019/10/30 19:11:01 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		countnbr(int n)
{
	int index;

	index = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		index++;
	}
	return (index);
}

char	*ft_itoapos(int n)
{
	char	*p;
	int		a;

	if (n >= 0)
	{
		a = countnbr(n);
		if (!(p = malloc(sizeof(char) * (a + 1))))
			return (NULL);
		p[a] = '\0';
		a--;
		while (a >= 0)
		{
			p[a] = n % 10 + '0';
			n = n / 10;
			a--;
		}
		return (p);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		a;

	if (n >= 0)
		return (p = ft_itoapos(n));
	if (n < 0)
	{
		a = countnbr(n);
		if (!(p = malloc(sizeof(char) * (a + 2))))
			return (NULL);
		p[a + 1] = '\0';
		p[0] = '-';
		while (a > 0)
		{
			p[a] = (n % 10) * -1 + '0';
			n = n / 10;
			a--;
		}
		return (p);
	}
	return (NULL);
}
