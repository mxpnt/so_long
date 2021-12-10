/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 13:27:32 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/09 10:15:26 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

void	ft_print_g(t_game *g, t_map *m, t_img *i)
{
	mlx_put_image_to_window(g->mlx, g->win, i->img_g, m->x * 28, \
	m->y * 32);
}

void	ft_print_w(t_game *g, t_map *m, t_img *i)
{
	mlx_put_image_to_window(g->mlx, g->win, i->img_w, m->x * 28, \
	m->y * 32);
}

void	ft_print_e(t_game *g, t_map *m, t_img *i)
{
	mlx_put_image_to_window(g->mlx, g->win, i->img_e, m->x * 28, \
	m->y * 32);
}

void	ft_print_co(t_game *g, t_map *m, t_img *i)
{
	mlx_put_image_to_window(g->mlx, g->win, i->img_co, m->x * 28 + 5, \
	m->y * 32 + 9);
}

void	ft_print(t_game *g, t_map *m, t_img *i)
{
	m->y = -1;
	while (++m->y * 32 < m->hei)
	{
		m->x = -1;
		while (++m->x * 28 < m->wid)
		{
			if (m->map[m->y][m->x] == '0' || m->map[m->y][m->x] == 'C'
				|| m->map[m->y][m->x] == 'P' || m->map[m->y][m->x] == '1')
				ft_print_g(g, m, i);
			else if (m->map[m->y][m->x] == 'E')
				ft_print_e(g, m, i);
			if (m->map[m->y][m->x] == '1')
				ft_print_w(g, m, i);
			if (m->map[m->y][m->x] == 'P')
				ft_print_p(g, m, i);
			if (m->map[m->y][m->x] == 'C')
				ft_print_co(g, m, i);
		}
	}
}
