/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:33:37 by ahaddad           #+#    #+#             */
/*   Updated: 2020/11/28 03:46:47 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char			*strstart(char *str, char *set)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i] && set[j])
	{
		if (str[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (&str[i]);
}

int				strend(char *str, char *set)
{
	int			i;
	int			j;

	i = ft_strlen(str);
	j = 0;
	while (i > 0 && set[j])
	{
		if (str[i - 1] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p1;
	char		*p2;
	size_t		i;

	i = 0;
	p1 = (char *)dst;
	p2 = (char *)src;
	if (p1 == p2)
		return (p1);
	while (i < n)
	{
		p1[i] = p2[i];
		i++;
	}
	return (p1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*tab;
	char		*delt;
	char		*ptr;
	char		*string;
	size_t		i;

	tab = (char *)s1;
	delt = (char *)set;
	if (!s1 || !set)
		return (NULL);
	string = strstart(tab, delt);
	i = strend(string, delt);
	ptr = malloc(sizeof(char) * i + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, string, i);
	ptr[i] = '\0';
	return (ptr);
}
