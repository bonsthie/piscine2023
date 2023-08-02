/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 12:26:00 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/25 14:29:58 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = argc;
	j = -1;
	while (argv[--i] && i != 0)
	{
		while (argv[i][++j])
			write(1, &argv[i][j], 1);
		write(1, "\n", 1);
		j = -1;
	}
	return (1);
}
