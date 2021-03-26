/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:58:52 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/03 20:30:13 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void				*ft_memset(void *s, int c, size_t len)
{
	size_t			i;
	char			*tab;

	i = 0;
	tab = (char *)s;
	while (i < len)
	{
		tab[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

void				ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int					ft_strchr1(const char *str, char c)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void				ft_stringdel(char **string)
{
	free(*string);
	*string = NULL;
}

int					check_extension(char *path)
{
	int				len;

	len = ft_strlen(path);
	if (path[len - 4] != '.')
		return (0);
	if (path[len - 3] != 'c')
		return (0);
	if (path[len - 2] != 'u')
		return (0);
	if (path[len - 1] != 'b')
		return (0);
	return (1);
}
