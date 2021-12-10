/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:18:51 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/09 10:28:34 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

/*
** y = Ordonnée
** x = Abscisse
** py = Position joueur
** px = Position joueur
** widht = Dimension de la largeur en px
** height = Dimension de la hauteur en px
** map = Map remplit avec le .ber
** exit = Nb de sortie
** coll = Nb de collectible
** start = Nb de position de départ
*/

typedef struct s_map
{
	int		y;
	int		x;
	int		py;
	int		px;
	int		wid;
	int		hei;
	char	**map;
	int		exit;
	int		coll;
	int		start;
}				t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_map	*smap;
}				t_game;

typedef struct s_img
{
	void	*img_p;
	void	*img_pl;
	void	*img_pr;
	void	*img_pu;
	void	*img_w;
	void	*img_co;
	void	*img_e;
	void	*img_g;
	char	*addr;
	int		bpp;
	int		line;
	int		end;
	int		x[1];
	int		y[1];
}				t_img;

typedef struct s_all
{
	t_game	*g;
	t_map	*m;
	t_img	*i;
}				t_all;

int		ft_keyhook(int keycode, t_all *a);
void	ft_init_img(t_game *g, t_img *i);
int		ft_exit_win(t_all *a);

void	ft_print_g(t_game *g, t_map *m, t_img *i);
void	ft_print_w(t_game *g, t_map *m, t_img *i);
void	ft_print_e(t_game *g, t_map *m, t_img *i);
void	ft_print_co(t_game *g, t_map *m, t_img *i);
void	ft_print(t_game *g, t_map *m, t_img *i);

void	ft_print_p(t_game *g, t_map *m, t_img *i);
void	ft_print_pr(t_game *g, t_map *m, t_img *i);
void	ft_print_pl(t_game *g, t_map *m, t_img *i);
void	ft_print_pu(t_game *g, t_map *m, t_img *i);

int		ft_check_exit(t_all *a);;
void	ft_putnbr(int nb);
void	ft_free(t_map *m);

int		ft_nb_line(char *ber);
void	ft_atleast(t_map *map_info);
char	**ft_init(t_map *map_info, char *ber);
void	ft_delnl(t_map *map_info);
int		ft_parsing(t_map *map_info, char *ber);

int		ft_error_rect(t_map *map_info);
int		ft_error_char(t_map *map_info);
int		ft_error_wallx(t_map *map_info);
int		ft_error_wally(t_map *map_info);
int		ft_error_atleast(t_map *map_info);

int		ft_movement(int keycode, t_all *a);
int		ft_move_right(t_all *a);
int		ft_move_left(t_all *a);
int		ft_move_up(t_all *a);
int		ft_move_down(t_all *a);

void	ft_error_msg(t_map *m, int n);
int		ft_invalid_arg(char *str);

#endif