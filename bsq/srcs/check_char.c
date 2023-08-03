/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:20:45 by babonnet          #+#    #+#             */
/*   Updated: 2023/08/02 16:27:45 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

int	ft_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

int	valid_char(t_map *map)
{
	if (map->empty_char == map->obstacle || !ft_is_printable(map->empty_char))
		return (0);
	if (map->obstacle == map->fill_char || !ft_is_printable(map->obstacle))
		return (0);
	if (map->fill_char == map->empty_char || !ft_is_printable(map->fill_char))
		return (0);
	return (1);
}
