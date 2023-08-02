/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:16:51 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/15 22:55:50 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;

	while (*src && nb != 0){
		dest[i]= *src;
		src++;
		i++;
		nb--;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	printf("%s\n", ft_strncat(argv[1], argv[2], 2));
	printf("%s", strncat(argv[1], argv[2], 2));
}