/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:26:49 by obraiki           #+#    #+#             */
/*   Updated: 2022/03/18 16:47:13 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	if (s[len] == (char)c)
		return ((char *)&s[len]);
	while (i < len)
	{
		if (s[len - 1] == (char)c)
			return ((char *)&s[len - 1]);
		len--;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	i = -1;
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	while (s1[++i])
	{
		ptr[i] = s1[i];
	}
	j = 0;
	while (s2[j])
	{
		ptr[i++] = s2[j++];
	}
	free(s1);
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s, char *p)
{
	int	i;

	i = 0;
	while (s[i] && p[i] && s[i] == p[i])
		i++;
	return (s[i] - p[i]);
}
