/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:20:28 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/03 20:28:02 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <unistd.h>
#include "libft/libft.h"

void		ft_putstr1(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

void		free_tab(char *tab)
{
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

int			key_exit(void *r)
{
	(void)r;
	exit(0);
}

void		game(t_cub *cub, char **av, int ac)
{
	char	*line;
	int		fd;

	fd = 0;
	if (ac == 2 || (ac == 3 && (cub->s_bmp == 1)))
	{
		if (((fd = open(av[1], O_RDONLY)) < 1) || check_extension(av[1]) == 0)
			check_err(2, "erreur dans le fichier");
		while (get_next_line(fd, &line) > 0)
			pars(line, cub);
		cub->pars.tab = ft_split(cub->pars.p, '\n');
		check_map(cub);
		free(line);
		init(cub);
		draw_game(cub);
		mlx_hook(cub->win_ptr, 2, 0, deal_key, cub);
		mlx_hook(cub->win_ptr, 17, 0, key_exit, cub);
		mlx_loop(cub->mlx_ptr);
	}
	else if (ac != 2 && ac != 3)
		check_err(1, "erreur dans le nombre des arguments");
}

int			main(int ac, char **av)
{
	t_cub	cub;

	cub.s_bmp = 0;
	cub.pars.nbr_col = 0;
	cub.pars.nbr_line = 0;
	ft_bzero(&cub, sizeof(t_cub));
	cub.pars.p = "";
	if (ac == 3)
	{
		if ((ft_strlen(av[2]) == 6) && ft_strncmp(av[2], "--save", 6) == 0)
			cub.s_bmp = 1;
		else
			check_err(1, "11erreur dans le nombre des arguments");
	}
	game(&cub, av, ac);
	ft_free2d(cub.pars.tab);
	free(cub.pars.p);
	cub.pars.p = NULL;
	return (0);
}
