/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:10:52 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/30 21:31:10 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	main(int ac, char **av)
{
	t_dict	*tab;
	int		file;
	int		length;
	int		i;

	file = open("numbers.dict", O_RDONLY);
	length = file_line_count(file);
	close(file);
	file = open("numbers.dict", O_RDONLY);
	tab = parsing(file, length);
	if (ac == 1)
	{
		i = -1;
		while (++i <= length)
			free(tab[i].string);
		free(tab);
		return (0);
	}
	print_number(ft_atoi(av[1]), tab, length);
	i = -1;
	while (++i <= length)
		free(tab[i].string);
	free(tab);
}
