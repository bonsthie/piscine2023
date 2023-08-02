/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 23:21:03 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/23 15:38:58 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

void test_posibility(int (*comb)[SIZE],int **solution, int right, int left);




int *check_posibility(int bord[6][6], int (*list)[4])
{
	int i;
	int	j;
	int	last_sol[4] = {0};
	int result[4][4];
	int ***posibility;

	i = 0;
	posibility = malloc(4 * sizeof(int**));
	if (posibility == NULL)
		return (0);
	while (++i < 5)
	{
		test_posibility(list, posibility[i], bord[i][0], bord[i][5]);
		i++;
	}
}