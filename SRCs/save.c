/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 04:53:44 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/05 20:10:18 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			bmp_file_header(t_cub *rt, int *fd)
{
	int			file_size;
	int			first_pix;

	file_size = 14 + 40 + 4 + (rt->pars.screenw * rt->pars.screenh) * 4;
	first_pix = 14 + 40 + 4;
	write(*fd, "BM", 2);
	write(*fd, &file_size, 4);
	write(*fd, "\0\0\0\0", 4);
	write(*fd, &first_pix, 4);
}

void			bmp_file_info_header(t_cub *rt, int *fd)
{
	int			header_info_size;
	int			plane_nbr;
	int			count;

	header_info_size = 40;
	plane_nbr = 1;
	count = 0;
	write(*fd, &header_info_size, 4);
	write(*fd, &rt->pars.screenw, 4);
	write(*fd, &rt->pars.screenh, 4);
	write(*fd, &plane_nbr, 2);
	write(*fd, &rt->tex.bpp, 2);
	while (count < 28)
	{
		write(*fd, "\0", 1);
		count++;
	}
}

static	void	copy_data(t_cub *rt, int *fd)
{
	int			i;

	i = rt->pars.screenw * rt->pars.screenh;
	while (i > 0)
	{
		write(*fd, &rt->data[i], 4);
		i--;
	}
}

void			pixel_data(t_cub *rt, int *fd)
{
	int			i;
	int			size_line;
	int			save;
	int			p;

	i = 0;
	rt->tex.s_line /= 4;
	while (i < rt->pars.screenh)
	{
		p = 0;
		size_line = rt->tex.s_line;
		while (p < size_line && p != size_line)
		{
			save = rt->data[p + (i * rt->tex.s_line)];
			rt->data[p + (i * rt->tex.s_line)] =
				rt->data[size_line + (i * rt->tex.s_line - 1)];
			rt->data[size_line + (i * rt->tex.s_line - 1)] = save;
			p++;
			size_line--;
		}
		i++;
	}
	copy_data(rt, fd);
}

int				create_bmp(t_cub *rt)
{
	int			fd;

	fd = open("cub.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0666);
	if (fd < 0)
		check_err(1, "erreur dans le sauvegarde");
	bmp_file_header(rt, &fd);
	bmp_file_info_header(rt, &fd);
	pixel_data(rt, &fd);
	return (1);
}
