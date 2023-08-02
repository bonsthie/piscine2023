/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:30:07 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/27 12:47:40 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

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

int	index_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	length;
	int	nb;
	int	i;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	length = ft_strlen(base);
	if (double_check(base, length))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && index_base(str[i], base) != -1)
	{
		nb = (nb * length) + index_base(str[i], base);
		i++;
	}
	return (nb * sign);
}

#include <stdio.h>
int main()
{
	printf("%d", ft_atoi_base("-2147483648", "0123456789"));
}
