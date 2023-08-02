/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:43:12 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/15 23:05:43 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char str)
{
	if (str < 32 || str > 126)
		return (0);
	return (1);
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

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	write_hex(unsigned char c)
{
	char	hex[16];

	ft_strcpy(hex, "0123456789abcdef");
	ft_putchar('\\');
	ft_putchar(hex[c / 16]);
	ft_putchar(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_str_is_printable(str[i]))
			ft_putchar(str[i]);
		else
			write_hex((unsigned char)str[i]);
		i++;
	}
}
