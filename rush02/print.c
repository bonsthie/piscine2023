/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:10:32 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/30 21:26:23 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include <stdio.h>

void putstr(char *str)
{
	int i = -1;
	while(str[++i])
		write(1, &str[i], 1);
}

int	find_index(t_dict *tab, int index)
{
	int i;

	i = 0;
	while (tab[i].num != index)
		i++;
	return (i);
}

void find_three_digit(long int nb, t_dict *tab)
{
	int index;
	int find;

	if (nb / 100 != 0)
	{
		index = find_index(tab, nb/100);
		putstr(tab[index].string);
		write(1, " ", 1);
		index = find_index(tab, 100);
		putstr(tab[index].string);
		write(1, " ", 1);
	}
	nb = nb % 100;
	if (nb < 20)
	{
		index = find_index(tab, nb);
		putstr(tab[index].string);
	}
	else
	{
		find = (nb / 10) * 10;
		index = find_index(tab, find);
		putstr(tab[index].string);
		write(1, " ", 1);
		find = nb % 10;
		index = find_index(tab, find);
		putstr(tab[index].string);
	}
}

void print_number(long int nb, t_dict *tab, int length)
{
	int index;
	index = length - 1;
	while (tab[index].num > 100)
	{
		if (nb / tab[index].num != 0)
		{
			find_three_digit(nb / tab[index].num, tab);
			write(1, " ", 1);
			putstr(tab[index].string);
			write(1, " ", 1);
			nb = nb % tab[index].num;
		}
		index--;
	}
	find_three_digit(nb, tab);
}

