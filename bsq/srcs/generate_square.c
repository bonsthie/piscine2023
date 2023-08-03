/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_square.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:36:00 by psalame           #+#    #+#             */
/*   Updated: 2023/08/02 11:52:56 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>

int	check_carre_at_pos(t_square *square, t_map *map)
{
	int	i;

	if (square->y + square->size > map->height)
		return (0);
	if (square->x + square->size > map->width - 1)
		return (0);
	i = square->y;
	while (i < (square->y + square->size))
	{
		if (map->content[i][square->x + square->size - 1] == map->obstacle)
			return (0);
		i++;
	}
	i = square->x;
	while (i < (square->x + square->size))
	{
		if (map->content[square->y + square->size - 1][i] == map->obstacle)
			return (0);
		i++;
	}
	return (1);
}

t_square	*generate_square(int x, int y, t_map *map)
{
	t_square	*square;

	square = malloc(sizeof(t_square));
	if (square == NULL)
		return (NULL);
	square->x = x;
	square->y = y;
	square->size = 1;
	while (check_carre_at_pos(square, map) == 1)
		square->size += 1;
	square->size -= 1;
	return (square);
}
