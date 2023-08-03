/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:47:19 by psalame           #+#    #+#             */
/*   Updated: 2023/08/02 14:13:56 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>
#include <unistd.h>

void	set_map_solution(t_map *map, t_square *solution)
{
	int	x;
	int	y;

	y = solution->y;
	while (y < solution->y + solution->size)
	{
		x = solution->x;
		while (x < solution->x + solution->size)
		{
			map->content[y][x] = map->fill_char;
			x++;
		}
		y++;
	}
}

void	print_map_solution(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		write(1, map->content[y], map->width - 1);
		write(1, "\n", 1);
		y++;
	}
}

void	get_map_solution(char *mapstr)
{
	t_map		*map;
	t_square	*solution;

	if (mapstr == NULL)
		write(2, "map error\n", 10);
	else
	{
		map = is_map_valid(mapstr);
		if (map == NULL)
			write(2, "map error\n", 10);
		else
		{
			solution = generate_greater_square(map);
			if (solution != NULL)
			{
				set_map_solution(map, solution);
				free(solution);
			}
			print_map_solution(map);
			free_map(map);
		}
		free(mapstr);
	}
}

int	main(int argc, char **argv)
{
	char	*filecontent;
	int		i;

	if (argc == 1)
		get_map_solution(read_input());
	i = 1;
	while (i < argc)
	{
		filecontent = get_file_content(argv[i]);
		get_map_solution(filecontent);
		i++;
	}
	return (0);
}
