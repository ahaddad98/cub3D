/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:35:36 by ahaddad           #+#    #+#             */
/*   Updated: 2019/11/07 19:10:31 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ld;
	size_t	ls;
	size_t	i;

	ls = ft_strlen(src);
	if (!dest && size == 0)
		return (ls);
	ld = ft_strlen(dest);
	if (size <= ld)
		ls += size;
	else
		ls += ld;
	i = 0;
	while (ld + 1 < size && src[i])
	{
		dest[ld] = src[i];
		ld++;
		i++;
	}
	if (ld < size)
		dest[ld] = '\0';
	return (ls);
}
