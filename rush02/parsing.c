/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:19:48 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/30 20:16:31 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	file_line_count(int file)
{
	int		state;
	int		size;
	char	*buff;
	int		line_count;

	state = 0;
	line_count = 0;
	buff = malloc(1 * sizeof(char));
	if (buff == NULL)
		return (0);
	while (!state)
	{
		size = read(file, buff, 1);
		if (size == -1)
		{
			free(buff);
			return (line_count);
		}
		if (size == 0)
			state = 1;
		if (buff[0] == '\n')
				line_count++;
	}
	free(buff);
	return (line_count + 1);
}

char	*grep_word(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ' ')
		i++;
	i++;
	while (str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = 0;
	return (str);
}

t_dict	*file_dictonary(t_dict*dest, char *string)
{
	dest->num = ft_atoi(string);
	grep_word(string);
	dest->string = malloc((ft_strlen(string) + 1) * sizeof(char));
	if (dest->string == NULL)
		return (NULL);
	ft_strcpy(dest->string, string);
	return (dest);
}

t_dict	*parsing_line(t_dict	*dest, int file)
{
	char	*buff;
	char	*string;
	int		status;

	status = 1;
	buff = malloc(sizeof(char));
	string = malloc(255 * sizeof(char));
	if (buff == NULL || string == NULL)
	{
		free(buff);
		free(string);	
		return (NULL);
	}
	string[0] = 0;
	while (buff[0] != '\n' && status != 0)
	{
		status = read(file, buff, 1);
		if (buff[0] != '\n' && status != 0)
			ft_strncat(string, buff, 1);
	}
	file_dictonary(dest, string);
	free(buff);
	free(string);
	return (dest);
}

t_dict	*parsing(int file, int length)
{
	t_dict	*dest;
	int		i;

	i = 0;
	dest = malloc((length + 1) * sizeof(t_dict));
	if (dest == NULL)
		return (NULL);
	while (i < length)
	{
		parsing_line(&dest[i], file);
		i++;
	}
	dest[i].num = 0;
	dest[i].string = 0;
	return (sort(dest));
}