/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:20:42 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/30 18:12:40 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (*src && nb != 0)
	{
		dest[i] = src[j];
		j++;
		i++;
		nb--;
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

long int	ft_atoi(char *str)
{
	int	i;
	long int	nb;
	long int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * sign);
}

t_dict	*sort(t_dict	*dictionary)
{
	int	i;
	int	j;
	t_dict	temp;

	i = 0;
	while(dictionary[i].string != 0)
	{
		j = i + 1;
		while (dictionary[j].string != 0)
		{
			if (dictionary[i].num > dictionary[j].num)
			{
				temp = dictionary[i];
				dictionary[i] = dictionary[j];
				dictionary[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (dictionary);
}