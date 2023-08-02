/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.SIZE2.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 1SIZE:32:29 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/23 15:19:12 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

void copy_tab(int *dest, int *src)
{
	int i;

	i = -1;
	while (++i < 4)
		dest[i] = src[i];
}

void print_tab(int *tab)
{
	int	i;

	i = -1;
	while (++i < SIZE)
		printf("%d", tab[i]);
	printf("\n");
}

int *reverse_tab(int tab[SIZE])
{
	int min;
	int max;
	int temp;

	min = -1;
	max = SIZE;
	while (++min < --max)
	{
		temp = tab[min];
		tab[min] = tab[max];
		tab[max] = temp;
	}
	return (tab);
}

int is_valid(int *comb, int nb)
{	
	int i = -1;
	int max = 0;
	int see = 0;

	while (++i < SIZE)
	{
		if (comb[i] > max)
		{
			see++;
			max = comb[i];
		}
	}
	if (see != nb)
		return (0);
	return (1);
}

void test_posibility(int (*comb)[SIZE],int **solution, int right, int left)
{
	int	i;
	int solution_count;
	int size;

	i = 0;
	solution_count = 0;
	while (i < SIZE)
	{
		if (is_valid(comb[i], left) && is_valid(reverse_tab(comb[i]), right))
		{
			solution = malloc(5 * sizeof(int *));
			size = -1;
			while (++size < SIZE)
				solution[size] = malloc(SIZE * sizeof(int));
			copy_tab(solution[solution_count], comb[i]);
			print_tab(solution[solution_count]);
			solution_count++;
			printf("\n");
		}
		i++;
	}
}