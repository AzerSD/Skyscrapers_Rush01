/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:07:16 by coder             #+#    #+#             */
/*   Updated: 2023/10/29 10:20:48 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "is_valid_input.h"
#include "string.h"
#include <stdio.h>

int		solve(int board[4][4], int *clues);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display_solution(int board[4][4])
{
	int	row;
	int	col;

	row = 0;
	printf("------\n");
	while (row <= 3)
	{
		col = 0;
		while (col <= 3)
		{
			ft_putchar(board[row][col] + '0');
			if (col == 3)
				col++;
			else
				ft_putchar(' ');
			col++;
		}
		ft_putchar('\n');
		row++;
	}
	printf("------\n");
}

int	start_board(int *clues)
{	
	int	row;
	int	col;
	int	board[4][4];

	row = 0;
	while (row <= 3)
	{
		col = 0;
		while (col <= 3)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
	if (solve(board, clues))
		display_solution(board);
	else
		write(1, "Error\n", 6);
	return (0);
}

int	check_clues_value(char *arg, int *clues)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[0] == ' ' || (arg[31] == ' '))
			return (0);
		if ((arg[i] >= '1' && arg[i] <= '4') && ((arg[i + 1] == ' ')
				|| (!((arg[i + 1])) && (arg[i - 1] == ' '))))
		{
			clues[j] = (arg[i] - '0');
			j++;
			i++;
		}
		if (arg[i] == 32 && ((arg[i - 1] >= '1' && arg[i - 1] <= '4')
				&& (arg[i + 1] >= '1' && arg[i + 1] <= '4')))
			i++;
		else
			return (j);
	}
	return (j);
}

int	main(int argc, char **argv)
{
	int		clues[16];
	char	clue[31];

	if (argc == 2)
	{
		if (is_valid_input(argv[1], clue, clues))
			start_board(clues);
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
