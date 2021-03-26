/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 01:45:57 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/05 17:22:20 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

static	void		chexk_pos2(t_cub *cub)
{
	cub->pos.dirx = 0;
	cub->pos.diry = 1;
	cub->pos.planex = 0.66;
	cub->pos.planey = 0;
}

void				check_pos_tex(t_cub *cub)
{
	if (cub->pars.c == 'W')
	{
		cub->pos.dirx = 0;
		cub->pos.diry = -1;
		cub->pos.planex = -0.66;
		cub->pos.planey = 0;
	}
	if (cub->pars.c == 'N')
	{
		cub->pos.dirx = 1;
		cub->pos.diry = 0;
		cub->pos.planex = 0;
		cub->pos.planey = -0.66;
	}
	if (cub->pars.c == 'E')
	{
		cub->pos.dirx = -1;
		cub->pos.diry = 0.0;
		cub->pos.planex = 0;
		cub->pos.planey = 0.66;
	}
	if (cub->pars.c == 'S')
	{
		chexk_pos2(cub);
	}
}

static	char		**tab_2d(t_cub *cub, char **p, char **t)
{
	int			i;
	int			j;
	int			k;

	i = 0;
	while (i < cub->pars.nbr_col)
	{
		j = 0;
		while (j < (k = count_line(cub->pars.tab)))
		{
			t[i][j] = p[j][i];
			j++;
		}
		i++;
	}
	t[i - 1][j] = '\0';
	return (t);
}

static char			**replace(t_cub *cub)
{
	int				i;
	int				j;
	char			**p;

	j = 0;
	p = (char **)malloc((cub->pars.nbr_line) * sizeof(char *));
	while (j < cub->pars.nbr_line)
		p[j++] = (char *)malloc((cub->pars.nbr_col) * sizeof(char));
	i = 0;
	while (i < cub->pars.nbr_line)
	{
		j = 0;
		while (j < ft_strlen(cub->pars.tab[i]))
		{
			p[i][j] = cub->pars.tab[i][j];
			j++;
		}
		while (j < cub->pars.nbr_col)
		{
			p[i][j] = ' ';
			j++;
		}
		i++;
	}
	return (p);
}

void				map_trans_check(t_cub *cub)
{
	int			i;
	int			j;
	char		**t;
	char		**p;

	p = replace(cub);
	j = 0;
	t = (char **)malloc(cub->pars.nbr_col * sizeof(char *));
	while (j < cub->pars.nbr_col)
		t[j++] = (char *)malloc((count_line(cub->pars.tab)) * sizeof(char));
	t = tab_2d(cub, p, t);
	i = 1;
	while (i < cub->pars.nbr_col - 1)
	{
		p = ft_split(t[i], ' ');
		j = 0;
		while (j < count_line(p))
		{
			if (p[j][0] != '1' || p[j][ft_strlen(p[j]) - 1] != '1')
				check_err(1, "\n erreur dans la map.");
			j++;
		}
		i++;
	}
	ft_free2d(p);
}
