/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:33:14 by ahaddad           #+#    #+#             */
/*   Updated: 2020/11/15 00:49:49 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char		*ft_strchr(const char *str, int c)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)str;
	if (!res)
		return (NULL);
	while (res[i])
	{
		if (res[i] == c)
			return (&res[i]);
		i++;
	}
	if (c == '\0')
	{
		return (&res[i]);
	}
	return (0);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	char	*p;

	i = 0;
	while (s1[i] != '\0')
		i++;
	p = malloc(sizeof(char) * i + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char		*ft_strjoin_free(char *s1, char const *s2)
{
	char	*p;
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (s1 && s2)
	{
		p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (p == NULL)
			return (NULL);
		while (s1[j])
			p[i++] = s1[j++];
		while (s2[k])
			p[i++] = s2[k++];
		p[i] = '\0';
		free(s1);
		return (p);
	}
	return (NULL);
}

char		*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if ((!s) || (unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (ft_strdup(""));
	while (i < len)
	{
		p[i] = s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}

int			ft_strlen(const char *p)
{
	int		i;

	i = 0;
	if (!p)
		return (0);
	while (p[i])
	{
		i++;
	}
	return (i);
}
