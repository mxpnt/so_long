/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 09:46:21 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/09 10:15:00 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

void	ft_print_p(t_game *g, t_map *m, t_img *i)
{
	mlx_put_image_to_window(g->mlx, g->win, i->img_p, m->x * 28, \
	m->y * 32);
}

void	ft_print_pr(t_game *g, t_map *m, t_img *i)
{
	mlx_put_image_to_window(g->mlx, g->win, i->img_pr, m->x * 28, \
	m->y * 32);
}

void	ft_print_pl(t_game *g, t_map *m, t_img *i)
{
	mlx_put_image_to_window(g->mlx, g->win, i->img_pl, m->x * 28, \
	m->y * 32);
}

void	ft_print_pu(t_game *g, t_map *m, t_img *i)
{
	mlx_put_image_to_window(g->mlx, g->win, i->img_pu, m->x * 28, \
	m->y * 32);
}
