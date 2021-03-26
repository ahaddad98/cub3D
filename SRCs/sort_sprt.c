/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:12:17 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/02 18:55:53 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_swap_s_distance(int i, int j, t_cub *cub)
{
	double	tmp;

	tmp = cub->sp.sprited[i];
	cub->sp.sprited[i] = cub->sp.sprited[j];
	cub->sp.sprited[j] = tmp;
}

void		ft_swap_s_order(int i, int j, t_cub *cub)
{
	int		tmp;

	tmp = cub->sp.spriteorder[i];
	cub->sp.spriteorder[i] = cub->sp.spriteorder[j];
	cub->sp.spriteorder[j] = tmp;
	ft_swap_s_distance(i, j, cub);
}

void		ft_sort_sprites(t_cub *cub, int amount)
{
	int		i;
	int		j;

	i = -1;
	while (++i < amount)
	{
		j = i;
		while (++j < amount)
		{
			if (cub->sp.sprited[i] < cub->sp.sprited[j])
				ft_swap_s_order(i, j, cub);
		}
	}
}
