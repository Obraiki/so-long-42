/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:26:55 by obraiki           #+#    #+#             */
/*   Updated: 2022/03/19 17:45:39 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	you_lose(t_data *data)
{
	write(1, "you lose!", 9);
	ft_free(data);
}

void	enemy_right(int x, int y, t_data *data)
{	
	if (data->map[y][x + 1] == 'P')
		you_lose(data);
	data->map[y][x + 1] = 'X';
	data->map[y][x] = '0';
}

void	enemy_left(int x, int y, t_data *data)
{
	if (data->map[y][x - 1] == 'P')
		you_lose(data);
	data->map[y][x - 1] = 'X';
	data->map[y][x] = '0';
}

void	move_enemy(t_data *data)
{
	int			x;
	int			y;
	static int	i;

	check_index('X', &x, &y, data);
	if (i == 50 || i == 200)
	{
		enemy_right(x, y, data);
	}
	else if (i == 250 || i == 300)
		enemy_left(x, y, data);
	i++;
	if (i == 301)
		i = 0;
}
