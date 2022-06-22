/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:18 by obraiki           #+#    #+#             */
/*   Updated: 2022/03/19 16:17:45 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_moves(t_data *data)
{
	data->moves++;
}

void	ft_putstring(t_data data)
{
	char		*s;

	s = ft_itoa(data.moves);
	mlx_string_put(data.ptr, data.win, 0, 0, 0xffffff, "Moves :");
	mlx_string_put(data.ptr, data.win, 80, 0, 0xffffff, s);
	free(s);
}

void	xpm_to_image(t_data *data)
{
	data->p1 = mlx_xpm_file_to_image(data->ptr, \
	"./img/b1.xpm", &data->a, &data->b);
	data->p2 = mlx_xpm_file_to_image(data->ptr, \
	"./img/b2.xpm", &data->a, &data->b);
	data->ground = mlx_xpm_file_to_image(data->ptr, \
	"./img/ground.xpm", &data->a, &data->b);
	data->wall = mlx_xpm_file_to_image(data->ptr, \
	"./img/wall.xpm", &data->a, &data->b);
	data->c = mlx_xpm_file_to_image(data->ptr, \
	"./img/collect.xpm", &data->a, &data->b);
	data->odoor = mlx_xpm_file_to_image(data->ptr, \
	"./img/door.xpm", &data->a, &data->b);
	data->cdoor = mlx_xpm_file_to_image(data->ptr, \
	"./img/bab.xpm", &data->a, &data->b);
	data->enemy = mlx_xpm_file_to_image(data->ptr, \
	"./img/enemy.xpm", &data->a, &data->b);
}

void	put_image(t_data data, int x, int y)
{
	static int	c = 0;

	ft_putstring(data);
	mlx_put_image_to_window(data.ptr, data.win, data.ground, x * 26, y * 26);
	if (data.map[y][x] == 'P' && c >= 50)
		mlx_put_image_to_window(data.ptr, data.win, data.p1, x * 26, y * 26);
	else if (data.map[y][x] == 'P' && c < 50)
		mlx_put_image_to_window(data.ptr, data.win, data.p2, x * 26, y * 26);
	else if (data.map[y][x] == '1')
		mlx_put_image_to_window(data.ptr, data.win, data.wall, x * 26, y * 26);
	else if (data.map[y][x] == 'C')
		mlx_put_image_to_window(data.ptr, data.win, data.c, x * 26, y * 26);
	else if (data.map[y][x] == 'X')
		mlx_put_image_to_window(data.ptr, data.win, data.enemy, x * 26, y * 26);
	else if (data.map[y][x] == 'E' && count_collects(data))
		mlx_put_image_to_window(data.ptr, data.win, data.cdoor, x * 26, y * 26);
	else if (data.map[y][x] == 'E' && count_collects(data) == 0)
		mlx_put_image_to_window(data.ptr, data.win, data.odoor, x * 26, y * 26);
	move_enemy(&data);
	c++;
	if (c == 100)
		c = 0;
}

int	put_images(t_data *data)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			put_image(*data, i, j);
			i++;
		}
		j++;
	}
	return (0);
}
