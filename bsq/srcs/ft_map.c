/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 14:57:22 by babonnet          #+#    #+#             */
/*   Updated: 2023/08/02 16:28:56 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>

int	grid_definition(t_map *dest_map, char *map)
{
	int		fline_length;

	fline_length = ft_strlen_newline(map);
	if (fline_length <= 4)
		return (0);
	dest_map->height = ft_atoin(map, fline_length - 4);
	if (dest_map->height <= 0)
		return (0);
	dest_map->empty_char = map[fline_length - 4];
	dest_map->obstacle = map[fline_length - 3];
	dest_map->fill_char = map[fline_length - 2];
	if (!valid_char(dest_map))
		return (0);
	return (1);
}

void	fill_line(t_map *final_map, char *map, int *start_line, int i)
{
	int		end_line;
	char	str[4];

	str[0] = final_map->empty_char;
	str[1] = final_map->obstacle;
	str[2] = '\n';
	str[3] = 0;
	end_line = ft_strlen_newline(&map[*start_line]);
	if (end_line != final_map->width)
	{
		final_map->content[i] = NULL;
		return ;
	}
	final_map->content[i] = malloc((end_line + 1) * sizeof(char));
	if (final_map->content[i] == NULL)
		return ;
	if (ft_strncpy(final_map->content[i], &map[*start_line], end_line + 1, str))
		*start_line += end_line;
	else
	{
		free(final_map->content[i]);
		final_map->content[i] = NULL;
	}
}

t_map	*fill_column(t_map	*final_map, char *map)
{
	int	start_line;
	int	i;

	i = -1;
	start_line = ft_strlen_newline(map);
	final_map->width = ft_strlen_newline(&map[start_line]);
	while (++i < final_map->height)
	{
		fill_line(final_map, map, &start_line, i);
		if (final_map->content[i] == NULL)
		{
			free_map(final_map);
			return (NULL);
		}
	}
	if (map[start_line] != 0 || final_map->width <= 1)
	{
		free_map(final_map);
		return (NULL);
	}
	return (final_map);
}

t_map	*is_map_valid(char *map)
{
	t_map	*final_map;

	final_map = malloc(sizeof(t_map));
	if (final_map == NULL)
		return (NULL);
	if (!grid_definition(final_map, map))
	{
		free(final_map);
		return (NULL);
	}
	final_map->content = malloc(final_map->height * sizeof(char *));
	if (final_map->content == NULL)
	{
		free_map(final_map);
		return (NULL);
	}
	final_map = fill_column(final_map, map);
	return (final_map);
}

void	free_map(t_map	*map)
{
	int	i;

	if (map == NULL)
		return ;
	if (map->content != NULL)
	{
		i = 0;
		while (i < map->height)
		{
			if (map->content[i] != NULL)
				free(map->content[i]);
			else
				break ;
			i++;
		}		
		free(map->content);
	}
	free(map);
}
