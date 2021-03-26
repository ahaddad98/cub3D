/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 02:25:18 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/03 11:12:40 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ceil_color(t_cub *cub)
{
	int		x;

	x = 0;
	while (x < cub->pars.screenw)
	{
		cub->data[x + cub->dr.y * cub->pars.screenw] = cub->pars.cl_color;
		x++;
	}
}

void		floor_color(t_cub *cub)
{
	int x;

	x = 0;
	while (x < cub->pars.screenw)
	{
		cub->data[x + cub->dr.y * cub->pars.screenw] = cub->pars.fl_color;
		x++;
	}
}
