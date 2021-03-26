/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 22:16:45 by ahaddad           #+#    #+#             */
/*   Updated: 2019/11/08 18:24:00 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*ss;

	index = 0;
	if (!s || !f)
		return (NULL);
	if (!(ss = (char *)malloc(ft_strlen((char *)s) + 1)))
		return (NULL);
	while (s[index])
	{
		ss[index] = (*f)(index, s[index]);
		index++;
	}
	ss[index] = '\0';
	return (ss);
}
