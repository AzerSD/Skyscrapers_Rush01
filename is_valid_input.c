/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:13:50 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 16:13:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is_valid_input.h"
#include <stdio.h>
#include "string.h"

int	check(char clue, int index)
{
	if (index % 2 == 0)
	{
		if (!is_numeric(clue))
			return (0);
	}
	else
	{
		if (!is_space(clue))
			return (0);
	}
	return (1);
}

int	is_valid_input(char *argv, char *clues, int *intClues)
{
	int	length;
	int	i;

	length = ft_strlen(argv);
	if (length != 31)
		return (0);
	ft_strcpy(clues, argv);
	i = 0;
	while (clues[i] != '\0')
	{
		if (!check(clues[i], i))
			return (0);
		i++;
	}
	remove_char(clues, ' ');
	i = 0;
	while (clues[i])
	{
		intClues[i] = clues[i] - '0';
		i++;
	}
	return (1);
}
