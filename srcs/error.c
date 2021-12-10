/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:48:26 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/03 16:38:19 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Check if the map is rectangular
*/

int	ft_error_rect(t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	if (!map_info->map[y])
		return (-1);
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
			x++;
		if (x != map_info->x)
			return (-1);
		y++;
	}
	return (0);
}

/* Check if all characters are valid
*/

int	ft_error_char(t_map *map_info)
{
	int	x;
	int	y;

	y = 0;
	if (!map_info->map[y])
		return (-1);
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] != '0' && map_info->map[y][x] != '1'
				&& map_info->map[y][x] != 'C' && map_info->map[y][x] != 'E'
				&& map_info->map[y][x] != 'P')
				return (-1);
			x++;
		}
		y++;
	}
	return (0);
}

/* Check if the map closed/surrounded by walls
*/

int	ft_error_wallx(t_map *map_info)
{
	int	x;
	int	y;

	x = 0;
	y = map_info->y - 1;
	if (!map_info->map[x])
		return (-1);
	while (map_info->map[0][x])
	{
		if (map_info->map[0][x] != '1')
			return (-1);
		x++;
	}
	x = 0;
	while (map_info->map[y][x])
	{
		if (map_info->map[y][x] != '1')
			return (-1);
		x++;
	}
	return (0);
}

int	ft_error_wally(t_map *map_info)
{
	int	x;
	int	y;

	x = map_info->x;
	y = 0;
	if (!map_info->map[y])
		return (-1);
	while (y < map_info->y)
	{
		if (map_info->map[y][0] != '1')
			return (-1);
		y++;
	}
	y = 0;
	while (y < map_info->y)
	{
		if (map_info->map[y][x - 1] != '1')
			return (-1);
		y++;
	}
	return (0);
}

/* Check if the map has at least one collectible/exit/starting postion
*/

int	ft_error_atleast(t_map *map_info)
{
	ft_atleast(map_info);
	if (map_info->exit == 0 || map_info->coll == 0 || map_info->start == 0)
		return (-1);
	return (0);
}
