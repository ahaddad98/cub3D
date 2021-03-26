/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 19:05:37 by ahaddad           #+#    #+#             */
/*   Updated: 2019/11/06 16:10:37 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	if (n == 0)
		return (NULL);
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	if (p2[i])
	{
		while (i < n)
		{
			p1[i] = p2[i];
			if (p2[i] == (unsigned char)c)
				return (p1 + i + 1);
			i++;
		}
	}
	return (0);
}
