/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:24:30 by abdait-m          #+#    #+#             */
/*   Updated: 2020/12/02 18:49:52 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		ft_set_textures(t_cub *cub)
{
	if (cub->dir.side == 0)
		cub->data[cub->dr.x + cub->dr.drawstart * cub->pars.screenw] =
			cub->tex.data[0][cub->tex.texy * cub->tex.wi[cub->dir.side] +
			cub->tex.texx];
	else if (cub->dir.side == 1)
		cub->data[cub->dr.x + cub->dr.drawstart * cub->pars.screenw] =
			cub->tex.data[1][cub->tex.texy * cub->tex.wi[cub->dir.side] +
			cub->tex.texx];
	else if (cub->dir.side == 2)
		cub->data[cub->dr.x + cub->dr.drawstart * cub->pars.screenw] =
			cub->tex.data[2][cub->tex.texy * cub->tex.wi[cub->dir.side] +
			cub->tex.texx];
	else if (cub->dir.side == 3)
		cub->data[cub->dr.x + cub->dr.drawstart * cub->pars.screenw] =
			cub->tex.data[3][cub->tex.texy * cub->tex.wi[cub->dir.side] +
			cub->tex.texx];
}

void		draw_text(t_cub *cub)
{
	while (cub->dr.drawstart++ < cub->dr.drawend)
	{
		cub->tex.texy = (int)cub->tex.texpos & (cub->tex.hi[cub->dir.side] - 1);
		cub->tex.texpos += cub->dir.step;
		ft_set_textures(cub);
	}
}

void		ft_walls_casting(t_cub *cub)
{
	calc_direction(cub);
	while (!cub->dir.hit)
		calc_side(cub);
	pos_draw(cub);
	other_sides(cub);
	if (cub->dir.side == 0 || cub->dir.side == 3)
		cub->tex.wallx = cub->pos.posy + cub->dir.perpwalldist *
			cub->dir.raydiry;
	else
		cub->tex.wallx = cub->pos.posx + cub->dir.perpwalldist *
			cub->dir.raydirx;
	cub->tex.wallx -= floor((cub->tex.wallx));
	cub->tex.texx = (int)(cub->tex.wallx *
			(double)(cub->tex.wi[cub->dir.side]));
	if ((cub->dir.side == 0 && cub->dir.raydirx > 0) || (cub->dir.side == 1 &&
				cub->dir.raydiry < 0))
		cub->tex.texx = cub->tex.wi[cub->dir.side] - cub->tex.texx - 1;
	cub->dir.step = 1.0 * cub->tex.hi[cub->dir.side] / cub->dr.lineheight;
	cub->tex.texpos = (cub->dr.drawstart - cub->pars.screenh /
			2 + cub->dr.lineheight
			/ 2) * cub->dir.step;
	draw_text(cub);
}
