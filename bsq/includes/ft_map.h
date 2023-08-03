/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:07:29 by psalame           #+#    #+#             */
/*   Updated: 2023/08/02 16:22:56 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_H
# define FT_MAP_H

typedef struct s_map {
	int			height;
	int			width;
	char		empty_char;
	char		obstacle;
	char		fill_char;
	char		**content;
}	t_map;
typedef struct s_square {
	int	x;
	int	y;
	int	size;
}	t_square;
t_map		*is_map_valid(char *map);
t_square	*generate_square(int x, int y, t_map *map);
t_square	*generate_greater_square(t_map *map);
char		*get_file_content(char *filename);
void		ft_putstr(char *str);
int			*ft_strncpy(char *dest, char *src, unsigned int n, char *chrset);
int			ft_strlen_newline(char *str);
char		*ft_strcpy_newline(char *dest, char *str);
int			ft_atoin(char *str, int size);
void		free_map(t_map	*map);
char		*read_input(void);
int			valid_char(t_map *map);

#endif