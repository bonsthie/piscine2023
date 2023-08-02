/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:54:14 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/13 12:46:21 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	i;
	int	buff[255];

	i = 0;
	if (nb == 0)
		ft_putchar('0');
	if (nb < 0)
		ft_putchar('-');
	while (nb != 0)
	{
		buff[i] = nb % 10;
		if (buff[i] < 0)
			buff[i] = -buff[i];
		nb /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(buff[i] + '0');
		i--;
	}
}
