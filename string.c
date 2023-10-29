/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:07:27 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 16:07:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

void	remove_char(char *str, char garbage)
{
	char	dst[31];
	int		is;
	int		id;

	is = 0;
	id = 0;
	while (str[is] != '\0')
	{
		while (str[is] == garbage)
			is++;
		dst[id] = str[is];
		is++;
		id++;
	}
	dst[id++] = '\0';
	ft_strcpy(str, dst);
}

int	is_numeric(char c)
{
	if (!(c >= '1' && c <= '4'))
		return (0);
	return (1);
}

int	is_space(char c)
{
	if (c != ' ')
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
