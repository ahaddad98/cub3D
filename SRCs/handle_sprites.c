/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:20:28 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/02 18:55:53 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		calc_sprt(t_cub *cub)
{
	cub->sp.sprx = 0.5 + cub->sp.spx[cub->sp.spriteorder[cub->sp.i]] -
		cub->pos.posx;
	cub->sp.spry = 0.5 + cub->sp.spy[cub->sp.spriteorder[cub->sp.i]] -
		cub->pos.posy;
	cub->sp.invdet = 1.0 / (cub->pos.planex * cub->pos.diry - cub->pos.dirx *
			cub->pos.planey);
	cub->sp.transformx = cub->sp.invdet * (cub->pos.diry * cub->sp.sprx -
			cub->pos.dirx * cub->sp.spry);
	cub->sp.transformy = cub->sp.invdet * (-cub->pos.planey * cub->sp.sprx
			+ cub->pos.planex * cub->sp.spry);
	cub->sp.sprscreenx = (int)((cub->pars.screenw / 2) * (1 +
				cub->sp.transformx / cub->sp.transformy));
	cub->sp.sprheight = abs((int)(cub->pars.screenh / (cub->sp.transformy)));
	cub->sp.drstarty = -cub->sp.sprheight / 2 + cub->pars.screenh / 2;
}

void		ft_init_sprite_vars(t_cub *cub)
{
	calc_sprt(cub);
	if (cub->sp.drstarty < 0)
		cub->sp.drstarty = 0;
	cub->sp.drendy = cub->sp.sprheight / 2 + cub->pars.screenh / 2;
	if (cub->sp.drendy >= cub->pars.screenh)
		cub->sp.drendy = cub->pars.screenh - 1;
	cub->sp.sprwidth = abs((int)(cub->pars.screenh / (cub->sp.transformy)));
	cub->sp.drstartx = -cub->sp.sprwidth / 2 + cub->sp.sprscreenx;
	if (cub->sp.drstartx < 0)
		cub->sp.drstartx = 0;
	cub->sp.drendx = cub->sp.sprwidth / 2 + cub->sp.sprscreenx;
	if (cub->sp.drendx >= cub->pars.screenw)
		cub->sp.drendx = cub->pars.screenw - 1;
}

void		ft_put_sprites_2_(t_cub *cub)
{
	cub->sp.texx = (int)(256 * (cub->sp.stripe - (-cub->sp.sprwidth / 2 +
					cub->sp.sprscreenx)) * cub->tex.wi[6] /
			cub->sp.sprwidth) / 256;
	if (cub->sp.transformy > 0 && cub->sp.stripe > 0 &&
			cub->sp.stripe < cub->pars.screenw &&
			cub->sp.transformy < cub->sp.zbuff[cub->sp.stripe])
	{
		cub->sp.y = cub->sp.drstarty;
		while (cub->sp.y < cub->sp.drendy)
		{
			cub->sp.d = (cub->sp.y) * 256 - cub->pars.screenh * 128 +
				cub->sp.sprheight * 128;
			cub->sp.texy = ((cub->sp.d * cub->tex.wi[6]) /
					cub->sp.sprheight) / 256;
			cub->sp.color = cub->tex.datas[cub->tex.wi[6] *
				cub->sp.texy + cub->sp.texx];
			if (cub->sp.color != 0 && cub->sp.color != 9961608)
				cub->data[cub->sp.y * cub->pars.screenw +
					cub->sp.stripe] = cub->sp.color;
			cub->sp.y++;
		}
	}
}

void		ft_put_sprites_1_(t_cub *cub)
{
	cub->sp.i = -1;
	while (cub->sp.i++ < cub->sp.numsprite)
	{
		cub->sp.spriteorder[cub->sp.i] = cub->sp.i;
		cub->sp.sprited[cub->sp.i] = ((cub->pos.posx - cub->sp.spx[cub->sp.i]) *
				(cub->pos.posx - cub->sp.spx[cub->sp.i]) + (cub->pos.posy -
					cub->sp.spy[cub->sp.i]) *
				(cub->pos.posy - cub->sp.spy[cub->sp.i]));
	}
	ft_sort_sprites(cub, cub->sp.numsprite);
	cub->sp.i = -1;
	while (++cub->sp.i < cub->sp.numsprite)
	{
		ft_init_sprite_vars(cub);
		cub->sp.stripe = cub->sp.drstartx;
		while (cub->sp.stripe < cub->sp.drendx)
		{
			ft_put_sprites_2_(cub);
			cub->sp.stripe++;
		}
	}
}
