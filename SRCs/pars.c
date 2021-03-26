/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:23:17 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/05 20:12:14 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int				count_line(char **tab)
{
	int			i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int				skip_spaces(char *line, t_cub *cub)
{
	cub->pars.i = 0;
	while (line[cub->pars.i] == ' ')
		cub->pars.i++;
	return (1);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	if (s1 && s2)
	{
		p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (p == NULL)
			return (NULL);
		while (s1[j])
		{
			p[i++] = s1[j++];
		}
		while (s2[k])
		{
			p[i++] = s2[k++];
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}

static	void	mp(t_cub *cub, char *line)
{
	if (line[cub->pars.i] != '1')
		check_err(1, "erreur dans la map \n");
	else
	{
		if (cub->pars.nbr_col < ft_strlen(line))
			cub->pars.nbr_col = ft_strlen(line);
		cub->pars.p = ft_strjoin(cub->pars.p, line);
		cub->pars.p = ft_strjoin(cub->pars.p, "\n");
	}
}

void			pars(char *line, t_cub *cub)
{
	if (*line == 'R')
		pars_resol(line, cub);
	if (ft_strncmp(line, "NO ", 3) == 0)
		pars_text_no(line, cub);
	if (ft_strncmp(line, "SO ", 3) == 0)
		pars_text_so(line, cub);
	if (ft_strncmp(line, "WE ", 3) == 0)
		pars_text_we(line, cub);
	if (ft_strncmp(line, "EA ", 3) == 0)
		pars_text_ea(line, cub);
	if (ft_strncmp(line, "S ", 2) == 0)
		pars_text_s(line, cub);
	if (ft_strncmp(line, "F", 1) == 0)
		pars_fl(line, cub);
	if (ft_strncmp(line, "C", 1) == 0)
		pars_cl(line, cub);
	skip_spaces(line, cub);
	if (line[cub->pars.i] == '1')
		mp(cub, line);
}
