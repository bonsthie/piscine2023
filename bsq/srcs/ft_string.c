/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:50:34 by psalame           #+#    #+#             */
/*   Updated: 2023/08/02 11:33:28 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	if (str != 0)
		while (*str)
			write(1, str++, 1);
}

int	ft_strchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strncpy(char *dest, char *src, unsigned int n, char *chrset)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		if (!ft_strchar(chrset, src[i]))
			return (0);
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (1);
}

int	ft_strlen_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (i);
}

char	*ft_strcpy_newline(char *dest, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
