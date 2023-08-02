/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:49:46 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/30 20:07:45 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H


typedef struct s_dict
{
	long int	num;
	char		*string;
}	t_dict;

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>


int		ft_strlen(char *str);
char	*ft_strncat(char *dest, char *src, unsigned int nb);
char	*ft_strcpy(char *dest, char *src);
long int		ft_atoi(char *str);
int		file_line_count(int file);
void	print_number(long int nb, t_dict *tab, int length);
t_dict	*parsing(int file, int length);
t_dict	*sort(t_dict	*dictionary);

#endif

