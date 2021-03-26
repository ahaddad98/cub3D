/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:39:42 by ahaddad           #+#    #+#             */
/*   Updated: 2019/10/24 11:00:17 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		p;

	i = 0;
	p = -1;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			p = i;
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	if (p != -1)
		return ((char *)s + p);
	return (NULL);
}
