/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:35:40 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/31 14:02:24 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *sep, char c)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_len(char *str, char *sep)
{
	int	word;
	int	i;

	i = 0;
	word = 0;
	while (str[i])
	{
		while (str[i] && is_charset(sep, str[i]))
			i++;
		if (str[i])
			word++;
		while (str[i] && !is_charset(sep, str[i]))
			i++;
	}
	return (word);
}

int	ft_strlen_split(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(sep, str[i]))
		i++;
	return (i);
}

char	**ft_split(char *str, char *sep)
{
	char	**strs;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	strs = malloc((word_len(str, sep) + 1) * sizeof(char *));
	while (++i < word_len(str, sep))
	{
		j = 0;
		while (str[k] && is_charset(sep, str[k]))
			k++;
		strs[i] = malloc((ft_strlen_split(&str[k], sep) + 1) * sizeof(char));
		while (str[k] && !is_charset(sep, str[k]))
			strs[i][j++] = str[k++];
		strs[i][j] = 0;
	}
	strs[i] = 0;
	return (strs);
}
