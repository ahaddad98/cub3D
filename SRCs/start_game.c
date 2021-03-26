/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 11:24:39 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/05 20:17:08 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void		draw_game(t_cub *cub)
{
	mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
	cub->dr.y = -1;
	while (++cub->dr.y < cub->pars.screenh / 2)
		ceil_color(cub);
	cub->dr.y--;
	while (++cub->dr.y < cub->pars.screenh)
		floor_color(cub);
	cub->dr.x = -1;
	while (++cub->dr.x < cub->pars.screenw)
		ft_walls_casting(cub);
	ft_put_sprites_1_(cub);
	if (cub->s_bmp == 1)
	{
		create_bmp(cub);
		check_err(1, "save");
	}
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img_ptr, 0, 0);
}

void		ft_upload_textures(t_cub *cub)
{
	cub->img_ptr = mlx_new_image(cub->mlx_ptr,
			cub->pars.screenw, cub->pars.screenh);
	cub->data = (int *)mlx_get_data_addr(cub->img_ptr, &cub->tex.bpp,
			&cub->tex.s_line, &cub->tex.endian);
	cub->tex.imgw[0] = mlx_xpm_file_to_image(cub->mlx_ptr, cub->pars.path_no,
			&cub->tex.wi[0], &cub->tex.hi[0]);
	cub->tex.data[0] = (int *)mlx_get_data_addr(cub->tex.imgw[0],
			&cub->tex.bpp, &cub->tex.s_line, &cub->tex.endian);
	cub->tex.imgw[1] = mlx_xpm_file_to_image(cub->mlx_ptr, cub->pars.path_so,
			&cub->tex.wi[1], &cub->tex.hi[1]);
	cub->tex.data[1] = (int *)mlx_get_data_addr(cub->tex.imgw[1],
			&cub->tex.bpp, &cub->tex.s_line, &cub->tex.endian);
	cub->tex.imgw[2] = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->pars.path_we, &cub->tex.wi[2], &cub->tex.hi[2]);
	cub->tex.data[2] = (int *)mlx_get_data_addr(cub->tex.imgw[2],
			&cub->tex.bpp, &cub->tex.s_line, &cub->tex.endian);
	cub->tex.imgw[3] = mlx_xpm_file_to_image(cub->mlx_ptr,
			cub->pars.path_ea, &cub->tex.wi[3], &cub->tex.hi[3]);
	cub->tex.data[3] = (int *)mlx_get_data_addr(cub->tex.imgw[3],
			&cub->tex.bpp, &cub->tex.s_line, &cub->tex.endian);
	cub->tex.imgs = mlx_xpm_file_to_image(cub->mlx_ptr, cub->pars.path_s,
			&cub->tex.wi[6], &cub->tex.hi[6]);
	cub->tex.datas = (int *)mlx_get_data_addr(cub->tex.imgs, &cub->tex.bpp,
			&cub->tex.s_line, &cub->tex.endian);
}

void		ft_search_for_sprites(t_cub *cub)
{
	int		i;
	int		k;
	int		j;

	i = 0;
	k = 0;
	while (i < cub->pars.nbr_line)
	{
		j = 0;
		while (j < cub->pars.nbr_col)
		{
			if (cub->pars.tab[i][j] == '2')
			{
				cub->sp.numsprite++;
				cub->sp.spx[k] = i;
				cub->sp.spy[k] = j;
				k++;
			}
			j++;
		}
		i++;
	}
}

void		init(t_cub *cub)
{
	cub->dr.x = 0;
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr,
			cub->pars.screenw, cub->pars.screenh, "CUB3D");
	ft_search_for_sprites(cub);
	ft_upload_textures(cub);
	ft_stringdel(&cub->pars.path_ea);
	ft_stringdel(&cub->pars.path_no);
	ft_stringdel(&cub->pars.path_so);
	ft_stringdel(&cub->pars.path_we);
	ft_stringdel(&cub->pars.path_s);
}
