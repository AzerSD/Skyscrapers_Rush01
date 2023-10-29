/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 16:11:44 by coder             #+#    #+#             */
/*   Updated: 2022/02/13 16:11:44 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
void	display_solution(int board[4][4]);
int	check_clues(int board[4][4], int *clues);

/*
 * Responsible for incrementing the indexes in the board
 * will stop at every 0 so we can change the 0 in the solve function
*/
int	find_zero(int board[4][4], int *row, int *col)
{
	*row = 0;
	while (*row <= 3)
	{
		*col = 0;
		while (*col <= 3)
		{
			if (!(board[*row][*col]))
				return (0);
			*col += 1;
		}
		*row += 1;
	}
	return (1);
}

/*
 *	ensure that placing a number n in a specific row and column of the grid
 *	is valid.	
*/
int	check_col(int board[4][4], int col, int n)
{
	int	row;

	row = 0;
	while (row <= 3)
	{
		if (board[row][col] == n)
			return (0);
		row++;
	}
	return (1);
}

/*
 *	ensure that placing a number n in a specific row and column of the grid
 *	is valid according to the rules of the sky scraper puzzle.	
*/
int	check_row(int board[4][4], int row, int n)
{
	int	col;

	col = 0;
	while (col <= 3)
	{
		if (board[row][col] == n)
			return (0);
		col++;
	}
	return (1);
}

/*
 *	This function checks whether placing a certain number n at a specific position (row, col) on the board is a valid move.
 *	It calls two helper functions check_row and check_col to ensure n is not present in the current row and column.
 *	Additionally, it checks if the current position (row, col) is not already filled (board[row][col] is 0).
 *	If all conditions are met, it returns 1 indicating that placing n at (row, col) is valid. Otherwise, it returns 0.
*/
int	check_clone(int board[4][4], int row, int col, int n)
{	
	if ((check_row(board, row, n)) && (check_col(board, col, n))
		&& (!(board[row][col])))
		return (1);
	return (0);
}

int	solve(int board[4][4], int *clues)
{
	int	n;
	int	row;
	int	col;

	if (find_zero(board, &row, &col) && (check_clues(board, clues)))
		return (1);
	n = 1;
	while (n <= 4)
	{
		if (check_clone(board, row, col, n))
		{
			board[row][col] = n;
			display_solution(board);
			if (solve(board, clues))
				return (1);
			board[row][col] = 0;
		}
		n++;
	}
	printf("###################\n");
	return (0);
}
