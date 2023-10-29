/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asioud <asioud@42heilbronn.de>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:07:59 by coder             #+#    #+#             */
/*   Updated: 2023/10/29 10:16:35 by asioud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_up_column(int board[4][4], int flag, int col)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = 1;
	tmp = board[0][col];
	while (i <= 3)
	{
		if (board[i][col] > tmp)
		{
			tmp = board[i][col];
			j++;
		}
		i++;
	}
	if (j == flag)
		return (0);
	return (1);
}

int	check_down_column(int board[4][4], int flag, int col)
{
	int	i;
	int	j;
	int	tmp;

	i = 2;
	j = 1;
	tmp = board[3][col];
	while (i >= 0)
	{
		if (board[i][col] > tmp)
		{
			tmp = board[i][col];
			j++;
		}
		i--;
	}
	if (j == flag)
		return (0);
	return (1);
}

int	check_left_row(int board[4][4], int flag, int row)
{
	int	i;
	int	j;
	int	tmp;

	i = 1;
	j = 1;
	tmp = board[row][0];
	while (i <= 3)
	{
		if (board[row][i] > tmp)
		{
			tmp = board[row][i];
			j++;
		}
		i++;
	}
	if (j == flag)
		return (0);
	return (1);
}

int	check_right_row(int board[4][4], int flag, int row)
{
	int	i;
	int	j;
	int	tmp;

	i = 2;
	j = 1;
	tmp = board[row][3];
	while (i >= 0)
	{
		if (board[row][i] > tmp)
		{
			tmp = board[row][i];
			j++;
		}
		i--;
	}
	if (j == flag)
		return (0);
	return (1);
}

/*
 * Check if a single number that we just placed in the grid is in a valid position or not
*/
int	check_clues(int board[4][4], int *clues)
{
	int	i;

	i = 0;
	while (clues[i])
	{
		if (i >= 0 && i <= 3)
			if (check_up_column(board, clues[i], i))
				return (0);
		if (i >= 4 && i <= 7)
			if (check_down_column(board, clues[i], i - 4))
				return (0);
		if (i >= 8 && i <= 11)
			if (check_left_row(board, clues[i], i - 8))
				return (0);
		if (i >= 12 && i <= 15)
			if (check_right_row(board, clues[i], i - 12))
				return (0);
		i++;
	}
	return (1);
}
