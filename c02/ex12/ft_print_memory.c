/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 19:30:53 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/15 15:28:24 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	write_hex(char c)
{
	char	hex[16];

	ft_strcpy(hex, "0123456789abcdef");
	ft_putchar(hex[c]);
}

void	ft_putnbr(long nb)
{
	int	i;
	long	buff[255];

	i = 0;
	while (nb != 0)
	{
		buff[i] = nb % 16;
		if (buff[i] < 0)
			buff[i] = -buff[i];
		nb /= 16;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write_hex(buff[i]);
		i--;
	}
}



#include <stdio.h>

void	*ft_print_memory(void *addr, unsigned int size)
{
	int i;
	long	str;

	str = (long)addr;
	printf("%lx\n", str);
	i = 0;
	ft_putnbr(str);
	return (addr);
}



int main()
{
	int i = 0;
	char test[] = "asdfghj";
	
	ft_print_memory(test, 10);
} 