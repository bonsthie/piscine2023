/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 08:45:55 by gviaud            #+#    #+#             */
/*   Updated: 2023/07/22 15:41:51 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int *ft_atoi(char *str, int *arr)
{
	int i;

	i = 0;
	
	while(str[i])
	{
		arr[i] = str[i] - '0';
		i++;
	}
	return(arr);
}

int valid_arg(char *dest, char *src)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (src[i] != '\0')
	{
		if(src[i] == ' ' || (src[i] >= 9 && src[i] <= 13))
			i++;
		else if((src[i] >= '1' && src[i] <= '4') && \
		(src[i + 1] == ' ' || (src[i + 1] >= 9 && \
		src[i + 1] <= 13) || (src[i + 1] == '\0')))
			{
			dest[j] = src[i];
			j++;
			i++;
			}
		else
			return (1);
	}
	return (j);
}

void	converter(int *arr, int tab[6][6])
{
	int	i;
	int	j;
	int	border;
	
	i = 0;
	border = 1;
	while (i <= 16)
	{
		j = 0;
		while (j < 4)
		{
			if(border == 1)
				tab[0][j + 1] = arr[i];
			if(border == 2)
				tab[5][j + 1] = arr[i];
			if(border == 3)
				tab[j + 1][0] = arr[i];
			if(border == 4)
				tab[j + 1][5] = arr[i];
			i++;
			j++;
		}
		border++;
	}
}

int	main(int argc, char **argv)
{
	char	conditions[17];
	int	tab[6][6];
	int	arr[15];
	int	i;
	int	k;

	k = 0;
	i = 0;
	if(argc != 2)
	{
		write(1, "Error", 5);
		return(0);
	}
	if(valid_arg(conditions, argv[1]) != 16)
		{
			write(1, "Error", 5);
			return(0);
		}
	ft_atoi(conditions, arr);
	converter(arr, tab);
	while(i <= 5)
	{
		k = 0;
		while (k <= 5)
		{
		printf("%i ", tab[i][k]);
		k++;
		}
		printf("\n");
		i++;
	}
	line_test(tab);
}

