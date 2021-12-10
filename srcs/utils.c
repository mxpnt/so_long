/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:51:21 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/09 10:24:32 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Check if all collectibles have picked up
*/

int	ft_check_exit(t_all *a)
{
	ft_atleast(a->m);
	if (a->m->coll == 0)
		return (1);
	return (0);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = nb % 10 + 48;
	write(1, &nb, 1);
}

void	ft_free(t_map *m)
{
	int	j;

	j = 0;
	while (m->map[j])
	{
		free(m->map[j]);
		j++;
	}
	free(m->map[j]);
}
