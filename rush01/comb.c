/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:57:06 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/22 23:34:17 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void test_posibility(int (*comb)[4], int right, int left);
void check_posibility(int bord[6][6], int (*list)[4]);

void	ft_strcpy(int *dest, int *src)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dest[i] = src[i];
		i++;
	}
}

void swap(int* x, int* y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(int *str,int (*comb)[4], int l, int r, int *row)
{
    int i;
    if (l == r)
	{
		ft_strcpy(comb[*row], str);
		*row += 1;
	}
	else {
		i = l;
        while (i <= r) 
		{
			swap(&str[l], &str[i]);
			permute(str, comb, l + 1, r, row);
			swap(&str[l], &str[i]);
			i++;
        }
    }
}

int main()
{
	int i = 0;
	int j = 0;
    int str[] = {1, 2, 3, 4};
	int comb[24][4];
	int row = 0;
	int test[6][6] = {
		{0, 4, 1, 2, 2, 0},
		{2, 0, 0 ,0, 0, 3},
		{3, 0, 0, 0, 0, 2},
		{2, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2},
		{0, 1, 4, 2, 2, 0}
	};
    permute(str, comb, 0, 3, &row);
	check_posibility(test, comb);
}