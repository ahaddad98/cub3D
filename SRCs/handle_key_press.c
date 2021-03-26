/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_press.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:24:19 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/05 16:49:00 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		calc_mov(t_cub *cub)
{
	if (cub->pars.tab[(int)(cub->pos.posx - cub->pos.planex *
				0.4)][(int)cub->pos.posy] == '0')
		cub->pos.posx -= cub->pos.planex * 0.4;
	if (cub->pars.tab[(int)(cub->pos.posx)][(int)(cub->pos.posy -
				cub->pos.planey * 0.4)] == '0')
		cub->pos.posy -= cub->pos.planey * 0.4;
}

void		calc_mov1(t_cub *cub)
{
	if (cub->pars.tab[(int)(cub->pos.posx + cub->pos.planex *
				0.4)][(int)cub->pos.posy] == '0')
		cub->pos.posx += cub->pos.planex * 0.4;
	if (cub->pars.tab[(int)cub->pos.posx][(int)(cub->pos.posy +
				cub->pos.planey * 0.4)] == '0')
		cub->pos.posy += cub->pos.planey * 0.4;
}

void		calc_rot(t_cub *cub)
{
	cub->pos.olddirx = cub->pos.dirx;
	cub->pos.oldplanex = cub->pos.planex;
	cub->pos.dirx = cub->pos.dirx * cos(-0.1) - cub->pos.diry * sin(-0.1);
	cub->pos.diry = cub->pos.olddirx * sin(-0.1) +
		cub->pos.diry * cos(-0.1);
	cub->pos.planex = cub->pos.planex * cos(-0.1) -
		cub->pos.planey * sin(-0.1);
	cub->pos.planey = cub->pos.oldplanex * sin(-0.1) +
		cub->pos.planey * cos(-0.1);
}

void		move_keys(int key, t_cub *cub)
{
	if (key == 13)
	{
		if (cub->pars.tab[(int)(cub->pos.posx + cub->pos.dirx *
					0.3)][(int)cub->pos.posy] == '0')
			cub->pos.posx += cub->pos.dirx * 0.3;
		if (cub->pars.tab[(int)cub->pos.posx][(int)(cub->pos.posy +
					cub->pos.diry * 0.3)] == '0')
			cub->pos.posy += cub->pos.diry * 0.3;
	}
	else if (key == 1)
	{
		if (cub->pars.tab[(int)(cub->pos.posx - cub->pos.dirx *
					0.3)][(int)cub->pos.posy] == '0')
			cub->pos.posx -= cub->pos.dirx * 0.3;
		if (cub->pars.tab[(int)(cub->pos.posx)][(int)(cub->pos.posy -
					cub->pos.diry * 0.3)] == '0')
			cub->pos.posy -= cub->pos.diry * 0.3;
	}
	else if (key == 0)
		calc_mov(cub);
	else if (key == 2)
		calc_mov1(cub);
}

int			deal_key(int key, t_cub *cub)
{
	if (key == 123)
	{
		cub->pos.olddirx = cub->pos.dirx;
		cub->pos.oldplanex = cub->pos.planex;
		cub->pos.dirx = cub->pos.dirx * cos(0.1) - cub->pos.diry * sin(0.1);
		cub->pos.diry = cub->pos.olddirx * sin(0.1) + cub->pos.diry * cos(0.1);
		cub->pos.planex = cub->pos.planex * cos(0.1) -
			cub->pos.planey * sin(0.1);
		cub->pos.planey = cub->pos.oldplanex * sin(0.1) +
			cub->pos.planey * cos(0.1);
	}
	if (key == 124)
		calc_rot(cub);
	move_keys(key, cub);
	draw_game(cub);
	if (key == 53)
	{
		exit(0);
	}
	return (0);
}
