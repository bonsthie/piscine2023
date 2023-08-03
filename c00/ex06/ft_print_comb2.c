/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 23:02:24 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/11 23:52:21 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	display(int a)
{
	char	tens;
	char	units;

	if (a < 10)
	{
		ft_putchar('0');
		ft_putchar(a + '0');
	}
	else
	{
		tens = (a / 10) + '0';
		units = (a % 10) + '0';
		ft_putchar(tens);
		ft_putchar(units);
	}
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = -1;
	while (++a <= 98)
	{
		b = a;
		while (++b <= 99)
		{
			display(a);
			ft_putchar(' ');
			display(b);
			if (!(a == 98 && b == 99))
			{
				write(1, ", ", 2);
			}
		}
	}
}
