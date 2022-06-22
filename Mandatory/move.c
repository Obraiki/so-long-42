/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:12 by obraiki           #+#    #+#             */
/*   Updated: 2022/03/19 17:59:39 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_index(char c, int *x, int *y, t_data *data)
{
	*y = 0;
	while (data->map[*y])
	{
		*x = 0;
		while (data->map[*y][*x])
		{
			if (data->map[*y][*x] == c)
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	check_index('P', &x, &y, data);
	if (data->map[y][x + 1] == '0')
	{
		data->map[y][x + 1] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y][x + 1] == 'C')
	{
		data->map[y][x + 1] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y][x + 1] == 'X')
		you_lose(data);
	if (data->map[y][x + 1] == 'E' && count_collects(*data) == 0)
	{
		put_moves(data);
		write(1, "You Win!\n", 9);
		ft_free(data);
	}
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	check_index('P', &x, &y, data);
	if (data->map[y][x - 1] == '0')
	{
		data->map[y][x - 1] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y][x - 1] == 'C')
	{
		data->map[y][x - 1] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y][x - 1] == 'X')
		you_lose(data);
	if (data->map[y][x - 1] == 'E' && count_collects(*data) == 0)
	{
		put_moves(data);
		write(1, "You Win!\n", 9);
		ft_free(data);
	}
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	check_index('P', &x, &y, data);
	if (data->map[y - 1][x] == '0')
	{
		data->map[y - 1][x] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y - 1][x] == 'C')
	{
		data->map[y - 1][x] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y - 1][x] == 'X')
		you_lose(data);
	if (data->map[y - 1][x] == 'E' && count_collects(*data) == 0)
	{
		put_moves(data);
		write(1, "You Win!\n", 9);
		ft_free(data);
	}
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	check_index('P', &x, &y, data);
	if (data->map[y + 1][x] == '0')
	{
		data->map[y + 1][x] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y + 1][x] == 'C')
	{
		data->map[y + 1][x] = 'P';
		data->map[y][x] = '0';
		put_moves(data);
	}
	if (data->map[y + 1][x] == 'X')
		you_lose(data);
	if (data->map[y + 1][x] == 'E' && count_collects(*data) == 0)
	{
		put_moves(data);
		write(1, "You Win!\n", 9);
		ft_free(data);
	}
}
