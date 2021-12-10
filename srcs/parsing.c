/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 10:47:04 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/09 10:33:15 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_nb_line(char *ber)
{
	int		fd;
	int		count;
	char	*str;

	fd = open(ber, O_RDONLY);
	count = 0;
	str = get_next_line(fd);
	while (str)
	{
		count++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	ft_atleast(t_map *map_info)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	map_info->exit = 0;
	map_info->coll = 0;
	map_info->start = 0;
	while (map_info->map[y])
	{
		x = 0;
		while (map_info->map[y][x])
		{
			if (map_info->map[y][x] == 'E')
				map_info->exit += 1;
			else if (map_info->map[y][x] == 'C')
				map_info->coll += 1;
			else if (map_info->map[y][x] == 'P')
				map_info->start += 1;
			x++;
		}
		y++;
	}
}

char	**ft_init(t_map *map_info, char *ber)
{
	int		fd;
	char	*str;
	char	**map;
	int		y;

	map_info->y = ft_nb_line(ber);
	map = malloc((map_info->y + 1) * sizeof(char *));
	if (!map)
		return (0);
	fd = open(ber, O_RDONLY);
	y = 0;
	while (y < map_info->y)
	{
		str = get_next_line(fd);
		map[y] = str;
		y++;
	}
	close(fd);
	map[y] = 0;
	return (map);
}

void	ft_delnl(t_map *map_info)
{
	int	x;
	int	y;
	int	p;

	y = -1;
	p = 0;
	while (map_info->map[++y])
	{
		x = -1;
		while (map_info->map[y][++x])
		{
			if (map_info->map[y][x] == '\n')
				map_info->map[y][x] = '\0';
			if ((map_info->map[y][x] && !p) || map_info->map[y][x] != 'P')
				map_info->map[y][x] = map_info->map[y][x];
			else
				map_info->map[y][x] = '0';
			if (map_info->map[y][x] == 'P' && p == 0)
			{
				map_info->py = y;
				map_info->px = x;
				p++;
			}
		}
	}
}

int	ft_parsing(t_map *map_info, char *ber)
{
	map_info->map = ft_init(map_info, ber);
	if (!map_info->map)
		ft_error_msg(map_info, 5);
	ft_delnl(map_info);
	map_info->x = ft_strlen(map_info->map[0]);
	if (ft_error_rect(map_info) == -1)
		ft_error_msg(map_info, 1);
	else if (ft_error_char(map_info) == -1)
		ft_error_msg(map_info, 2);
	else if (ft_error_wallx(map_info) == -1
		|| ft_error_wally(map_info) == -1)
		ft_error_msg(map_info, 3);
	else if (ft_error_atleast(map_info) == -1)
		ft_error_msg(map_info, 4);
	map_info->wid = map_info->x * 28;
	map_info->hei = map_info->y * 32;
	return (0);
}
