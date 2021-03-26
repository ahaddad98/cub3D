/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_text.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:56:40 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/05 16:30:16 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void			pars_text_no(char *line, t_cub *cub)
{
	char		**p;
	int			fd;

	if (!(p = ft_split(line + 3, ' ')))
		check_err(5, "erreur dans path de txt north");
	if ((fd = open(p[0], O_RDONLY)) < 0)
		check_err(5, "erreur dans path de txt north");
	if (fd > 0)
		cub->pars.path_no = p[0];
	else if (count_line(p) != 1)
	{
		check_err(5, "erreur dans la path north");
		ft_free2d(p);
	}
}

void			pars_text_so(char *line, t_cub *cub)
{
	char		**p;
	int			fd;

	if (!(p = ft_split(line + 3, ' ')))
		check_err(5, "erreur dans path de txt south");
	if ((fd = open(p[0], O_RDONLY)) < 0)
		check_err(5, "erreur dans path de txt south");
	if (fd > 0)
		cub->pars.path_so = p[0];
	else if (count_line(p) != 1)
	{
		check_err(5, "erreur dans la path south");
		ft_free2d(p);
	}
}

void			pars_text_we(char *line, t_cub *cub)
{
	char		**p;
	int			fd;

	if (!(p = ft_split(line + 3, ' ')))
		check_err(5, "erreur dans la path weast");
	if ((fd = open(p[0], O_RDONLY)) < 0)
		check_err(5, "erreur dans path de txt weast");
	if (fd > 0)
		cub->pars.path_we = p[0];
	else if (count_line(p) != 1)
	{
		check_err(5, "erreur dans la path weast");
		ft_free2d(p);
	}
}

void			pars_text_ea(char *line, t_cub *cub)
{
	char		**p;
	int			fd;

	if (!(p = ft_split(line + 3, ' ')))
		check_err(5, "erreur dans la  path east");
	if ((fd = open(p[0], O_RDONLY)) < 0)
		check_err(5, "erreur dans la  path east");
	if (fd > 0)
		cub->pars.path_ea = p[0];
	else if (count_line(p) != 1)
	{
		check_err(5, "erreur dans la  path east");
		ft_free2d(p);
	}
}

void			pars_text_s(char *line, t_cub *cub)
{
	char		**p;
	int			fd;

	if (!(p = ft_split(line + 2, ' ')))
		check_err(5, "erreur dans la  path sprite");
	if ((fd = open(p[0], O_RDONLY)) < 0)
		check_err(5, "erreur dans la  path sprite");
	if (fd > 0)
		cub->pars.path_s = p[0];
	else if (count_line(p) != 1)
	{
		check_err(5, "ereur dans la path S");
		ft_free2d(p);
	}
}
