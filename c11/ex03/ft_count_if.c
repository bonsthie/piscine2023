/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:57:54 by babonnet          #+#    #+#             */
/*   Updated: 2023/08/03 00:15:31 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int count;

	i = -1;
	count = 0;
	while(++i < length)
		if (f(tab[i]) != 0)
			count++;
	return (count);
}
