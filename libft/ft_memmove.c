/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:53:06 by ahaddad           #+#    #+#             */
/*   Updated: 2019/11/02 11:53:24 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*usrc;
	unsigned char	*udst;

	usrc = (unsigned char *)src;
	udst = (unsigned char *)dst;
	if (udst < usrc)
	{
		i = 0;
		while (i < len)
		{
			udst[i] = usrc[i];
			i++;
		}
	}
	else if (udst > usrc)
	{
		i = len;
		while (i > 0)
		{
			udst[i - 1] = usrc[i - 1];
			i--;
		}
	}
	return (udst);
}
