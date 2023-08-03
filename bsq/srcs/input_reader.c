/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:12:13 by psalame           #+#    #+#             */
/*   Updated: 2023/08/02 22:59:36 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	*realloc_str(char *content, int oldsize, int newsize)
{
	char	*newalloc;
	int		i;

	if (content == NULL)
		return (NULL);
	newalloc = malloc(newsize * sizeof(char));
	if (newalloc == NULL)
		return (NULL);
	i = 0;
	while (i < oldsize && i < newsize)
	{
		newalloc[i] = content[i];
		i++;
	}
	free(content);
	return (newalloc);
}

char	*read_input(void)
{
	char	*content;
	int		size;
	int		alloc_size;
	int		oldsize;

	content = malloc(200 * sizeof(char));
	content[0] = 0;
	alloc_size = 200;
	size = 0;
	oldsize = 1;
	while (size != oldsize && content != NULL)
	{
		oldsize = size;
		size = size + read(0, content + size, 199);
		content[size] = '\n';
		if (size + 200 >= alloc_size)
		{
			content = realloc_str(content, alloc_size, alloc_size + 200);
			alloc_size += 200;
		}
	}
	if (content != NULL)
		content[size] = 0;
	return (content);
}
