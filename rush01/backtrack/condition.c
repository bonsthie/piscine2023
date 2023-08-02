/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:57:07 by gviaud            #+#    #+#             */
/*   Updated: 2023/07/23 14:25:21 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define SIZE 4

int check_colonne(int tab, int colonne);

int	is_present(int **tab, int line, int column, int nb)
{
	int	i;

	i = 0;
	while(i < SIZE)
	{
		if (tab[line][i] == nb)
			return (1);
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		if (tab[i][column])
			return (1);
		i++;
	}
	return (0);
}

int is_valid(int **tab, int line, int column, int nb)
{
    if(is_present(tab, line, column, nb))
    	return (1);
    return (0);
}
