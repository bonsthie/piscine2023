/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 13:37:29 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/24 11:23:06 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	test;

	test = 2;
	if (nb == 2147483647)
		return (2147483647);
	if (nb <= 1)
		return (0);
	while (test <= (nb / 2))
	{
		if (nb % test == 0)
			return (ft_find_next_prime(nb + 1));
		test++;
	}
	return (nb);
}
