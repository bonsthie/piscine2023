/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:29:49 by psalame           #+#    #+#             */
/*   Updated: 2023/08/02 11:29:57 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoin(char *str, int size)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	while (i < size)
	{
		res = res * 10 + str[i] - '0';
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (res);
}
