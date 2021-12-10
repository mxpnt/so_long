/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:56:16 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/09 10:27:49 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

int	ft_keyhook(int keycode, t_all *a)
{
	static int	nb_move = 0;

	if (nb_move == 0)
	{
		a->m->x = a->m->px;
		a->m->y = a->m->py;
	}
	if (ft_movement(keycode, a) == 1)
	{
		nb_move++;
		ft_putnbr(nb_move);
		write(1, "\n", 1);
	}
	else if (keycode == 53 || ft_movement(keycode, a) == 2)
	{
		if (ft_movement(keycode, a) == 2)
		{
			ft_putnbr(nb_move + 1);
			write(1, "\nGood Job !\n", 12);
		}
		ft_exit_win(a);
		exit(0);
	}
	return (0);
}

void	ft_init_img(t_game *g, t_img *i)
{
	i->img_g = mlx_xpm_file_to_image(g->mlx, "img/g.xpm", i->x, i->y);
	i->img_w = mlx_xpm_file_to_image(g->mlx, "img/w.xpm", i->x, i->y);
	i->img_e = mlx_xpm_file_to_image(g->mlx, "img/e.xpm", i->x, i->y);
	i->img_co = mlx_xpm_file_to_image(g->mlx, "img/co.xpm", i->x, i->y);
	i->img_p = mlx_xpm_file_to_image(g->mlx, "img/p.xpm", i->x, i->y);
	i->img_pl = mlx_xpm_file_to_image(g->mlx, "img/pl.xpm", i->x, i->y);
	i->img_pr = mlx_xpm_file_to_image(g->mlx, "img/pr.xpm", i->x, i->y);
	i->img_pu = mlx_xpm_file_to_image(g->mlx, "img/pu.xpm", i->x, i->y);
}

int	ft_exit_win(t_all *a)
{
	mlx_destroy_image(a->g->mlx, a->i->img_g);
	mlx_destroy_image(a->g->mlx, a->i->img_w);
	mlx_destroy_image(a->g->mlx, a->i->img_e);
	mlx_destroy_image(a->g->mlx, a->i->img_co);
	mlx_destroy_image(a->g->mlx, a->i->img_p);
	mlx_destroy_image(a->g->mlx, a->i->img_pl);
	mlx_destroy_image(a->g->mlx, a->i->img_pr);
	mlx_destroy_image(a->g->mlx, a->i->img_pu);
	mlx_destroy_window(a->g->mlx, a->g->win);
	ft_free(a->m);
	write(1, "Thanks for playing !\n", 21);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_map	map_info;
	t_game	game;
	t_img	img;
	t_all	a;

	if (argc != 2 || ft_invalid_arg(argv[1]))
		ft_error_msg(&map_info, 0);
	ft_parsing(&map_info, argv[1]);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, map_info.wid, map_info.hei, "ISAAK");
	ft_init_img(&game, &img);
	ft_print(&game, &map_info, &img);
	a.g = &game;
	a.i = &img;
	a.m = &map_info;
	mlx_key_hook(game.win, ft_keyhook, &a);
	mlx_hook(a.g->win, 17, 0, ft_exit_win, &a);
	mlx_loop(game.mlx);
	return (0);
}
