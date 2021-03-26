/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 03:43:50 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/05 16:27:18 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static int		check(int reslt, int b, int count)
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

int				ft_atoi(char *str)
{
	int			a;
	int			b;
	int			c;
	int			counter;

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
	}
	return (check(c, b, counter));
}

int				check_err(int i, char *line)
{
	if (i > 0)
		ft_putstr1(line);
	exit(0);
}

void			ft_free2d(char **ptr)
{
	int			i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}
