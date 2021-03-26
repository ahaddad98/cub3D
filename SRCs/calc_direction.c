/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:23:45 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/02 18:46:39 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		pos_draw(t_cub *cub)
{
	if (cub->dir.side == 0)
		cub->dir.perpwalldist = (cub->pos.mapx - cub->pos.posx + (1 -
					cub->dir.stepx) / 2) / cub->dir.raydirx;
	else
		cub->dir.perpwalldist = (cub->pos.mapy - cub->pos.posy + (1 -
					cub->dir.stepy) / 2) / cub->dir.raydiry;
	cub->dr.lineheight = (int)(cub->pars.screenh / cub->dir.perpwalldist);
	cub->dr.drawstart = -cub->dr.lineheight / 2 + cub->pars.screenh / 2;
	cub->dr.drawend = cub->dr.lineheight / 2 + cub->pars.screenh / 2;
	if (cub->dr.drawstart < 0)
		cub->dr.drawstart = 0;
	if (cub->dr.drawend >= cub->pars.screenh)
		cub->dr.drawend = cub->pars.screenh - 1;
	cub->sp.zbuff[cub->dr.x] = cub->dir.perpwalldist;
}

void		calc_side(t_cub *cub)
{
	if (cub->dir.sidedistx < cub->dir.sidedisty)
	{
		cub->dir.sidedistx += cub->dir.deltasistx;
		cub->pos.mapx += cub->dir.stepx;
		cub->dir.side = 0;
	}
	else
	{
		cub->dir.sidedisty += cub->dir.deltadisty;
		cub->pos.mapy += cub->dir.stepy;
		cub->dir.side = 1;
	}
	if (cub->pars.tab[cub->pos.mapx][cub->pos.mapy] == '1')
	{
		cub->dir.hit = 1;
	}
}

void		calc_sidedist(t_cub *cub)
{
	if (cub->dir.raydirx < 0)
	{
		cub->dir.stepx = -1;
		cub->dir.sidedistx = (cub->pos.posx - cub->pos.mapx)
			* cub->dir.deltasistx;
	}
	else
	{
		cub->dir.stepx = 1;
		cub->dir.sidedistx = (cub->pos.mapx + 1.0 - cub->pos.posx)
			* cub->dir.deltasistx;
	}
	if (cub->dir.raydiry < 0)
	{
		cub->dir.stepy = -1;
		cub->dir.sidedisty = (cub->pos.posy - cub->pos.mapy)
			* cub->dir.deltadisty;
	}
	else
	{
		cub->dir.stepy = 1;
		cub->dir.sidedisty = (cub->pos.mapy + 1.0 - cub->pos.posy)
			* cub->dir.deltadisty;
	}
}

void		calc_direction(t_cub *cub)
{
	cub->pos.camerax = 2 * cub->dr.x / (double)cub->pars.screenw - 1;
	cub->dir.raydirx = cub->pos.dirx + cub->pos.planex * cub->pos.camerax;
	cub->dir.raydiry = cub->pos.diry + cub->pos.planey * cub->pos.camerax;
	cub->pos.mapx = (int)cub->pos.posx;
	cub->pos.mapy = (int)cub->pos.posy;
	cub->dir.deltasistx = fabs(1 / cub->dir.raydirx);
	cub->dir.deltadisty = fabs(1 / cub->dir.raydiry);
	cub->dir.hit = 0;
	if (cub->dir.raydiry == 0)
		cub->dir.deltasistx = 0;
	else if (cub->dir.raydirx == 0)
		cub->dir.deltasistx = 1;
	else
		cub->dir.deltasistx = fabs(1 / cub->dir.raydirx);
	if (cub->dir.raydirx == 0)
		cub->dir.deltadisty = 0;
	else if (cub->dir.raydiry == 0)
		cub->dir.deltadisty = 1;
	else
		cub->dir.deltadisty = fabs(1 / cub->dir.raydiry);
	calc_sidedist(cub);
}

void		other_sides(t_cub *cub)
{
	if (cub->dir.side == 1 && cub->dir.raydiry < 0)
	{
		cub->dir.side = 2;
	}
	else if (cub->dir.side == 0 && cub->dir.raydirx < 0)
	{
		cub->dir.side = 3;
	}
}
