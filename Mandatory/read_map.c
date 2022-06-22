/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:27:24 by obraiki           #+#    #+#             */
/*   Updated: 2022/03/19 13:06:19 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_line(t_data *d, char	*str)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	j = 0;
	e = 0;
	while (d->map[i])
		i++;
	i--;
	while (str[j])
	{
		if (str[j] == '\n')
			e++;
		j++;
	}
	if (e != i)
		put_error();
}

char	*ft_read(int fd)
{
	char		*buff;
	int			n;
	static char	*res;

	buff = (char *)malloc(sizeof(char) * (2));
	if (!buff)
		return (NULL);
	n = 1;
	while (n)
	{
		n = read(fd, buff, 1);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		res = ft_strjoin(res, buff);
	}
	free (buff);
	return (res);
}

void	read_map(char *filename, t_data *data)
{
	int		fd;		
	char	*str;

	fd = open(filename, O_RDONLY);
	str = ft_read(fd);
	ft_check_content(str);
	data->map = ft_split(str, '\n');
	check_line(data, str);
	free (str);
}
