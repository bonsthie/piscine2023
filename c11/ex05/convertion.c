/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 20:47:41 by babonnet          #+#    #+#             */
/*   Updated: 2023/08/03 20:48:05 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr(int nb)
{
	unsigned int	newnb;
	char			c;

	if (nb < 0)
	{
		newnb = -(nb + 1) + 1;
		write(1, "-", 1);
	}
	else
		newnb = nb;
	if (newnb >= 10)
		ft_putnbr(newnb / 10);
	c = newnb % 10 + '0';
	write(1, &c, 1);
}

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(char *str)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}