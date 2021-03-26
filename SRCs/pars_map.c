/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:23:08 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/05 20:11:56 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		get_map(t_cub *cub)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	cub->pars.check_m = 0;
	while (i < cub->pars.nbr_line - 1)
	{
		j = 0;
		while (j < cub->pars.nbr_col - 1)
		{
			if (cub->pars.tab[i][j] == 'N' || cub->pars.tab[i][j] == 'S'
					|| cub->pars.tab[i][j]
					== 'W' || cub->pars.tab[i][j] == 'E')
				cub->pars.check_m++;
			j++;
		}
		i++;
	}
}

void		check_line_m(t_cub *cub)
{
	char	**p;
	int		j;

	p = ft_split(cub->pars.tab[0], ' ');
	j = 0;
	while (j < count_line(p))
	{
		if (p[j][0] != '1' || p[j][ft_strlen(p[j]) - 1] != '1'
				|| ft_strchr1(cub->pars.tab[0], '0') == 1)
			check_err(1, "erreur dans la map \n");
		j++;
	}
	p = ft_split(cub->pars.tab[cub->pars.nbr_line - 1], ' ');
	j = 0;
	while (j < count_line(p))
	{
		if (ft_strchr1(p[j], '0') == 1 || p[j][ft_strlen(p[j]) - 1] != '1'
				|| p[j][0] != '1')
			check_err(1, "erreur dans la map \n");
		j++;
	}
	ft_free2d(p);
}

void		get_side_pos(t_cub *cub)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (i < cub->pars.nbr_line - 1)
	{
		j = 0;
		while (j < cub->pars.nbr_col - 1)
		{
			if (cub->pars.tab[i][j] == 'N' || cub->pars.tab[i][j] == 'S'
					|| cub->pars.tab[i][j] == 'W' || cub->pars.tab[i][j] == 'E')
			{
				cub->pars.c = cub->pars.tab[i][j];
				cub->pos.posx = (double)i + 0.4;
				cub->pos.posy = (double)j + 0.4;
				cub->pars.tab[i][j] = '0';
			}
			j++;
		}
		i++;
	}
}

void		check_l2(t_cub *cub)
{
	int		i;
	int		j;
	char	**p;

	i = 1;
	j = 0;
	while (i < cub->pars.nbr_line - 1)
	{
		p = ft_split(cub->pars.tab[i], ' ');
		j = 0;
		while (j < count_line(p))
		{
			if (p[j][0] != '1' || p[j][ft_strlen(p[j]) - 1] != '1')
				check_err(1, "erreur dans la map \n");
			j++;
		}
		i++;
	}
	ft_free2d(p);
}

void		check_map(t_cub *cub)
{
	cub->pars.nbr_line = count_line(cub->pars.tab);
	if ((cub->pars.nbr_line < 2) || (cub->pars.nbr_col < 2))
		check_err(1, "erruer dans la map");
	check_line_m(cub);
	get_map(cub);
	if (cub->pars.check_m != 1)
		check_err(1, "erreur dans la map verifier la position ou le side");
	else
	{
		get_side_pos(cub);
		check_pos_tex(cub);
		cub->pars.v_m = 1;
	}
	check_l2(cub);
	map_trans_check(cub);
}
