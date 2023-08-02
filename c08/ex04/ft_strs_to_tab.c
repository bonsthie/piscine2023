/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 01:05:53 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/27 20:02:50 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*dest;

	dest = malloc((ac + 1) * sizeof(t_stock_str));
	if (dest == NULL)
		return (NULL);
	dest[ac].size = 0;
	dest[ac].str = 0;
	dest[ac].copy = 0;
	while (--ac >= 0)
	{
		dest[ac].size = ft_strlen(av[ac]);
		dest[ac].str = av[ac];
		dest[ac].copy = malloc((dest[ac].size + 1) * sizeof(char));
		ft_strcpy(dest[ac].copy, av[ac]);
	}
	return (dest);
}
