/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 14:17:36 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/09 09:57:05 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../mlx/mlx.h"

/*
** KEYCODE = 2 = D
** KEYCODE = 1 = S
** KEYCODE = 0 = A
** KEYCODE = 13 = W
** KEYCODE = 53 = ESC
*/

int	ft_movement(int keycode, t_all *a)
{
	if (keycode == 2)
		return (ft_move_right(a));
	if (keycode == 0)
		return (ft_move_left(a));
	if (keycode == 1)
		return (ft_move_down(a));
	if (keycode == 13)
		return (ft_move_up(a));
	return (0);
}

int	ft_move_right(t_all *a)
{
	if (a->m->map[a->m->y][a->m->x + 1] != '1')
	{
		if (a->m->map[a->m->y][a->m->x + 1] == 'E'
			&& ft_check_exit(a) == 0)
			return (0);
		else if (a->m->map[a->m->y][a->m->x + 1] == 'E'
			&& ft_check_exit(a) == 1)
		{	
			a->m->map[a->m->y][a->m->x] = '0';
			ft_print_g(a->g, a->m, a->i);
			return (2);
		}
		a->m->map[a->m->y][a->m->x] = '0';
		a->m->map[a->m->y][a->m->x + 1] = 'P';
		ft_print_g(a->g, a->m, a->i);
		a->m->x++;
		ft_print_pr(a->g, a->m, a->i);
		return (1);
	}
	return (0);
}

int	ft_move_left(t_all *a)
{
	if (a->m->map[a->m->y][a->m->x - 1] != '1')
	{
		if (a->m->map[a->m->y][a->m->x - 1] == 'E'
			&& ft_check_exit(a) == 0)
			return (0);
		else if (a->m->map[a->m->y][a->m->x - 1] == 'E'
			&& ft_check_exit(a) == 1)
		{	
			a->m->map[a->m->y][a->m->x] = '0';
			ft_print_g(a->g, a->m, a->i);
			return (2);
		}
		a->m->map[a->m->y][a->m->x] = '0';
		a->m->map[a->m->y][a->m->x - 1] = 'P';
		ft_print_g(a->g, a->m, a->i);
		a->m->x--;
		ft_print_pl(a->g, a->m, a->i);
		return (1);
	}
	return (0);
}

int	ft_move_up(t_all *a)
{
	if (a->m->map[a->m->y - 1][a->m->x] != '1')
	{
		if (a->m->map[a->m->y - 1][a->m->x] == 'E'
			&& ft_check_exit(a) == 0)
			return (0);
		else if (a->m->map[a->m->y - 1][a->m->x] == 'E'
			&& ft_check_exit(a) == 1)
		{	
			a->m->map[a->m->y][a->m->x] = '0';
			ft_print_g(a->g, a->m, a->i);
			return (2);
		}
		a->m->map[a->m->y][a->m->x] = '0';
		a->m->map[a->m->y - 1][a->m->x] = 'P';
		ft_print_g(a->g, a->m, a->i);
		a->m->y--;
		ft_print_pu(a->g, a->m, a->i);
		return (1);
	}
	return (0);
}

int	ft_move_down(t_all *a)
{
	if (a->m->map[a->m->y + 1][a->m->x] != '1')
	{
		if (a->m->map[a->m->y + 1][a->m->x] == 'E'
			&& ft_check_exit(a) == 0)
			return (0);
		else if (a->m->map[a->m->y + 1][a->m->x] == 'E'
			&& ft_check_exit(a) == 1)
		{	
			a->m->map[a->m->y][a->m->x] = '0';
			ft_print_g(a->g, a->m, a->i);
			return (2);
		}
		a->m->map[a->m->y][a->m->x] = '0';
		a->m->map[a->m->y + 1][a->m->x] = 'P';
		ft_print_g(a->g, a->m, a->i);
		a->m->y++;
		ft_print_p(a->g, a->m, a->i);
		return (1);
	}
	return (0);
}
