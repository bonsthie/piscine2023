/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_backtracking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:51:31 by cblonde           #+#    #+#             */
/*   Updated: 2023/07/23 16:43:46 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define SIZE 4

int is_valid(int **tab, int line, int colonne, int num);

/* int not_in_line(int num, int arr[6][6], int i)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (arr[i][j] == num)
			return (1);
		j++;
	}
	return (0);
} */

/* int not_in_column(int num, int arr[6][6], int j)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (arr[i][j] == num)
			return (1);
		i++;
	}
	return (0);
} */

void print_array(int **arr)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp = arr[i][j] + '0';
			write(1, &tmp, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}	
}

int backtracking(int **arr, int position)
{
	int i;
	int j;
	int num;
	int is_finish;

	num = 1;
	is_finish = 0;
	if (position == SIZE*SIZE)
	{
		is_finish = 1;
		return (0);
	}
	i = position / SIZE;
	j = position % SIZE;
	//if (i == 0 || j == 0 || i == 5 || j == 5)
	//	backtracking(arr, position + 1);
	while (num <= 4 && is_finish == 0)
	{
		if (!(is_valid(arr, j, i, num)))
		{
			arr[i][j] = num;
			//print_array(arr);
			//write(1, "\n", 1);
			if (backtracking(arr, position + 1))
				return (0);
		}
		num++;
	}
	return (1);
}


int	main(void)
{
	int	**arr;
	int	i;

	i = 0;
	arr = malloc(SIZE * sizeof(int*));
	if (arr == NULL)
		return (0);
	while (i < SIZE)
	{
		arr[i] = malloc(SIZE * sizeof(int));
		if (arr[i] == NULL)
			return (0);
		i++;
	}

	backtracking(arr, 0);
	print_array(arr);

	while (i >= 0)
	{
		free(arr[i]);
		i--;
	}
	free(arr);
	return (0);
}