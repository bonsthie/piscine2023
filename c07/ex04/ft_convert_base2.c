/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:56:04 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/31 10:57:50 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	double_check(char *base, int length)
{
	int	i;
	int	j;

	i = 0;
	if (length < 2)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (1);
		j = i;
		while (++j < length)
		{
			if (base[j] == base[i])
				return (1);
		}
		i++;
	}
	return (0);
}

void	transformation(unsigned int nb, char *base, int length)
{
	char	result[50];
	int		i;

	i = 0;
	while (nb > 0)
	{
		result[i] = base[nb % length];
		nb /= length;
		i++;
	}
	result[i] = 0;
	ft_strlen(result);
}

char	*ft_reverse_str(char *src)
{
	int		length;
	int		i;
	char	temp;

	i = -1;
	length = ft_strlen(src);
	if (src[0] == '-')
		i++;
	while (++i < --length)
	{
		temp = src[i];
		src[i] = src[length];
		src[length] = temp;
	}
	return (src);
}
