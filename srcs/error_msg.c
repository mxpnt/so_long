/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapontil <mapontil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:42:09 by mapontil          #+#    #+#             */
/*   Updated: 2021/12/09 10:30:36 by mapontil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_invalid_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	if (i < 4)
		return (1);
	if (str[i] == 'r' && str[i - 1] == 'e' && str[i - 2] == 'b'
		&& str[i - 3] == '.' && str[i - 4])
		return (0);
	else
		return (1);
}

void	ft_error_msg(t_map *m, int n)
{
	write(1, "Error\n", 6);
	if (n == 0)
		write(1, "Wrong number of valid arguments\n", 32);
	else if (n == 1)
		write(1, "The map is not rectangular\n", 27);
	else if (n == 2)
		write(1, "Wrong character in the map\n", 27);
	else if (n == 3)
		write(1, "The map is not closed/surrounded by walls\n", 42);
	else if (n == 4)
	{
		write(1, "The map has not at least one ", 29);
		write(1, "collectible/exit/starting postion\n", 34);
	}
	else if (n == 5)
		write(1, "Invalid map\n", 12);
	if (m->map)
		ft_free(m);
	exit (0);
}
