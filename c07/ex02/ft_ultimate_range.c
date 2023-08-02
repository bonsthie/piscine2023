/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:56:22 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/31 11:25:53 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	i = -1;
	if (min >= max)
		return (0);
	*range = malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	while (++i < (max - min))
		(*range)[i] = min + i;
	return (max - min);
}
