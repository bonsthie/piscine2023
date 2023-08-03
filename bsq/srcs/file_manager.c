/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psalame <psalame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:30:29 by psalame           #+#    #+#             */
/*   Updated: 2023/08/01 15:48:14 by psalame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	get_file_size(char *filename)
{
	int		filesize;
	int		file;
	char	tmp_buffer[1];

	if (filename == NULL)
		return (-1);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (-1);
	filesize = 0;
	while (read(file, tmp_buffer, 1))
		filesize++;
	close(file);
	return (filesize);
}

char	*get_file_content(char *filename)
{
	int		filesize;
	char	*filecontent;
	int		file;

	if (filename == NULL)
		return (NULL);
	filesize = get_file_size(filename);
	if (filesize == -1)
		return (NULL);
	file = open(filename, O_RDONLY);
	if (file == -1)
		return (NULL);
	filecontent = malloc((filesize + 1) * sizeof(char));
	if (filecontent == NULL)
		return (NULL);
	read(file, filecontent, filesize);
	filecontent[filesize] = 0;
	close(file);
	return (filecontent);
}
