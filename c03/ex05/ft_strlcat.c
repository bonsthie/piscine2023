/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 16:31:20 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/16 16:42:54 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

unsigned int ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while(dest[i] && i < size)
		i++;
	while (dest[i + j] && i < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	if ((i + j) < size)
		dest[i + j] = 0;
	j = ft_strlen(src);
	return(i + j);
}