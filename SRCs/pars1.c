/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:15:15 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/03 12:12:54 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			pars_resol(char *line, t_cub *cub)
{
	cub->pars.line_r = ft_split(line + 1, ' ');
	if (count_line(cub->pars.line_r) == 2)
	{
		cub->pars.screenw = ft_atoi(cub->pars.line_r[0]);
		cub->pars.screenh = ft_atoi(cub->pars.line_r[1]);
		if (cub->pars.screenw <= 0)
			check_err(5, "erreur dans scrrenW");
		if (cub->pars.screenh <= 0)
			check_err(5, "erreur dans scrrenh");
		if (cub->pars.screenw > 2560)
			cub->pars.screenw = 2560;
		if (cub->pars.screenh > 1440)
			cub->pars.screenh = 1440;
	}
	else
		check_err(6, "erruer dans les parametres");
	ft_free2d(cub->pars.line_r);
}

void			pars_fl(char *line, t_cub *cub)
{
	cub->pars.line_f = ft_split(line + 1, ' ');
	if (count_line(cub->pars.line_f) == 1)
	{
		cub->pars.rgb = ft_split(cub->pars.line_f[0], ',');
		if (count_line(cub->pars.rgb) == 3)
		{
			cub->pars.r_f = ft_atoi(cub->pars.rgb[0]);
			cub->pars.g_f = ft_atoi(cub->pars.rgb[1]);
			cub->pars.b_f = ft_atoi(cub->pars.rgb[2]);
			if (cub->pars.r_f > 255 || cub->pars.r_f < 0)
				check_err(8, "erreur dans le couleur du floor");
			if (cub->pars.g_f > 255 || cub->pars.g_f < 0)
				check_err(8, "erreur dans le couleur du floor");
			if (cub->pars.b_f > 255 || cub->pars.b_f < 0)
				check_err(8, "erreur dans le couleur du floor");
			ft_free2d(cub->pars.rgb);
			cub->pars.fl_color = (cub->pars.r_f * 65536) +
				(cub->pars.g_f * 256) + cub->pars.b_f;
		}
		else
			check_err(5, "erreur dans le nombre de donnee");
	}
	else
		check_err(5, "erreur dans le nombre des params");
	ft_free2d(cub->pars.line_f);
}

void			pars_cl(char *line, t_cub *cub)
{
	cub->pars.line_c = ft_split(line + 1, ' ');
	if (count_line(cub->pars.line_c) == 1)
	{
		cub->pars.rgb = ft_split(cub->pars.line_c[0], ',');
		if (count_line(cub->pars.rgb) == 3)
		{
			cub->pars.r_c = ft_atoi(cub->pars.rgb[0]);
			cub->pars.g_c = ft_atoi(cub->pars.rgb[1]);
			cub->pars.b_c = ft_atoi(cub->pars.rgb[2]);
			if (cub->pars.r_c > 255 || cub->pars.r_c < 0)
				check_err(8, "erreur dans le couleur du cl");
			if (cub->pars.g_c > 255 || cub->pars.g_c < 0)
				check_err(8, "erreur dans le couleur du cl");
			if (cub->pars.b_c > 255 || cub->pars.b_c < 0)
				check_err(8, "erreur dans le couleur du cl");
			ft_free2d(cub->pars.rgb);
			cub->pars.cl_color = (cub->pars.r_c * 65536) +
				(cub->pars.g_c * 256) + cub->pars.b_c;
		}
		else
			check_err(5, "erreur dans le nombre des parametres");
	}
	else
		check_err(5, "erreur dans le nombre des params");
	ft_free2d(cub->pars.line_c);
}
