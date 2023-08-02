/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:27:33 by babonnet          #+#    #+#             */
/*   Updated: 2023/07/15 23:07:47 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int	is_first_letter(char *str, int i)
{
	if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
		return (0);
	if (str[i - 1] >= 'a' && str[i - 1] <= 'z')
		return (0);
	if (str[i - 1] >= '0' && str[i - 1] <= '1')
		return (0);
	str[i] -= 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	lowercase(str);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			is_first_letter(str, i);
		i++;
	}
	return (str);
}
