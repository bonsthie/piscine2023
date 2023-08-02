/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 19:54:24 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/27 12:47:46 by babonnet         ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	int	length;

	length = ft_strlen(str);
	while (length-- != 0)
		write(1, &str[length], 1);
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
	char	result[255];
	int		i;

	i = 0;
	while (nb > 0)
	{
		result[i] = base[nb % length];
		nb /= length;
		i++;
	}
	result[i] = 0;
	ft_putstr(result);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	length;
	unsigned int	nb;

	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	if (nbr < 0)
	{
		nb = -nbr;
		write(1, "-", 1);
	}
	else
		nb = nbr;
	length = ft_strlen(base);
	if (double_check(base, length))
		return ;
	transformation(nb, base, length);
}
