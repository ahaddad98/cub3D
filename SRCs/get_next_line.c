/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:27:06 by ahaddad           #+#    #+#             */
/*   Updated: 2020/11/17 12:52:30 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static	int			leak_error(char *rt, int r)
{
	if (rt)
		free(rt);
	return (r);
}

static	char		*cond(char *rt, int r)
{
	if (rt[r] && rt[r + 1])
		return (ft_strdup(rt + r + 1));
	return (NULL);
}

static	int			norm(char *rt)
{
	int r;

	r = 0;
	while (rt[r] != '\n' && rt[r])
		r++;
	return (r);
}

int					get_next_line(int fd, char **line)
{
	char			*buf;
	int				r;
	static char		*rt;
	char			*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 ||\
			!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (leak_error(rt, -1));
	*line = NULL;
	while ((!ft_strchr(rt, '\n')) && ((r = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[r] = '\0';
		rt = ft_strjoin_free(rt, buf);
		if (rt == NULL)
			return (leak_error(rt, -1));
	}
	free(buf);
	if (r == -1 || (r == 0 && !ft_strlen(rt)))
		return (leak_error(rt, r));
	tmp = rt;
	r = norm(rt);
	*line = ft_substr(rt, 0, r);
	rt = cond(rt, r);
	free(tmp);
	return (1);
}
