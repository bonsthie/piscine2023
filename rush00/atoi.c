/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:33:37 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/15 16:18:05 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int width, int length);

int	ft_atoi(char *str)
{
	int	neg;
	int	i;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}

int	main(int argc, char **argv)
{
	int	length;
	int	width;

	if (argc > 3)
	{
		rush(0, 0);
		return (0);
	}
	width = ft_atoi(argv[1]);
	length = ft_atoi(argv[2]);
	rush(width, length);
	return (0);
}
