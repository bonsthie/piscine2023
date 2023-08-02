/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 10:49:50 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/15 13:40:35 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;

	while (*src){
		dest[i]= *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	printf("%s\n", ft_strcat(argv[1], argv[2]));
	printf("%s", strcat(argv[1], argv[2]));
}