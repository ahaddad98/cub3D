/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:11:44 by ahaddad           #+#    #+#             */
/*   Updated: 2020/12/02 17:16:06 by ahaddad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0 && n < 10)
		ft_putchar_fd((n + '0'), fd);
	else if (n > -10 && n < 0)
	{
		ft_putchar_fd(('-'), fd);
		ft_putchar_fd(((n * -1) + '0'), fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10 + '0'), fd);
	}
	else
	{
		ft_putchar_fd(('-'), fd);
		ft_putnbr_fd((-1 * (n / 10)), fd);
		ft_putchar_fd((-1 * (n % 10) + '0'), fd);
	}
}
