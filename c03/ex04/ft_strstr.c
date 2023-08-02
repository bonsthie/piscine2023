/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:43:20 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/16 16:48:02 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strstr(char *str, char *to_find)
{
	int i;
	int j;
	while (str[i])
	{
		while(str[i] == to_find[j])
		{
			i++;
			j++;
			if (to_find[j] == 0)
				return (&str[i - j]);
		}
		j = 0;
		i++;
		return (0);
	}
}