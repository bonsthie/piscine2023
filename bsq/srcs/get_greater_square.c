/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_greater_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:46:05 by psalame           #+#    #+#             */
/*   Updated: 2023/08/02 14:23:34 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>

t_square	*get_greater_square(t_square *square_a, t_square *square_b)
{
	if (square_a == NULL)
		return (square_b);
	if (square_b == NULL)
		return (square_a);
	if (square_b->size > square_a->size)
	{
		free(square_a);
		return (square_b);
	}
	else
	{
		free(square_b);
		return (square_a);
	}
}

t_square	*generate_greater_square(t_map *map)
{
	int			x;
	int			y;
	t_square	*greater_square;
	t_square	*current_square;

	y = 0;
	greater_square = NULL;
	while (y < map->height)
	{
		if (greater_square != NULL && (map->height - y) < greater_square->size)
			break ;
		x = 0;
		while (x < map->width)
		{
			if (greater_square != NULL
				&& (map->width - x) < greater_square->size)
				break ;
			current_square = generate_square(x, y, map);
			greater_square = get_greater_square(greater_square, current_square);
			x++;
		}
		y++;
	}
	return (greater_square);
}
