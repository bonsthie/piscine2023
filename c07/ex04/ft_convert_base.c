/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:24:09 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/31 17:19:07 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int				double_check(char *base, int length);
unsigned int	ft_strlen(char *str);
void			transformation(unsigned int nb, char *base, int length);
char			*ft_reverse_str(char *src);

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

int	convert_size(int base_size, int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		i++;
	while (nb != 0)
	{
		nb /= base_size;
		i++;
	}
	return (--i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int		base_ten;
	int				base_to_length;
	int				i;
	char			*result;

	base_to_length = ft_strlen(base_to);
	base_ten = ft_atoi_base(nbr, base_from);
	result = malloc(convert_size(base_to_length, base_ten + 1) * sizeof(char));
	i = 0;
	if (base_ten < 0)
	{
		result[i++] = '-';
		base_ten = -base_ten;
	}
	while (base_ten > 0)
	{
		result[i] = base_to[base_ten % base_to_length];
		base_ten /= base_to_length;
		i++;
	}
	result[i] = 0;
	return (ft_reverse_str(result));
}
