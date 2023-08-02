/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:42:28 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/31 11:26:55 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	calcul_final_len(int size, char **strs, char *sep)
{
	int	final_size;
	int	i;

	final_size = ft_strlen(sep) * (size - 1);
	i = -1;
	while (++i < size)
		final_size += ft_strlen(strs[i]);
	final_size++;
	return (final_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final_str;
	int		final_size;
	int		i;

	if (size == 0 || strs == NULL || sep == NULL)
	{
		final_str = malloc(sizeof(char));
		final_str[0] = 0;
		return (final_str);
	}
	final_size = calcul_final_len(size, strs, sep);
	final_str = malloc(final_size * sizeof(char));
	if (final_str == NULL)
		return (0);
	ft_strcpy(final_str, strs[0]);
	i = 0;
	while (++i < size)
	{
		ft_strcat(final_str, sep);
		ft_strcat(final_str, strs[i]);
	}
	return (final_str);
}
