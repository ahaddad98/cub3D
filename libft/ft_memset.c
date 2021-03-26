/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:53:45 by ahaddad           #+#    #+#             */
/*   Updated: 2019/11/06 18:52:12 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = (char *)s;
	while (i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
