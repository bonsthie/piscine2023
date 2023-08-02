/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colonne.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gviaud <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:23:48 by gviaud            #+#    #+#             */
/*   Updated: 2023/07/23 10:54:30 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int colonne_up(int tab[6][6], int colonne)
{
	int temp;
	int i;
	int count;
	
	temp = 0;
	i = 1;
	count = 0;
	while(i < 5)
	{
		if(tab[i][colonne] > temp)
		{
			count++;
			temp = tab[i][colonne];
		}
		i++;
	}
		if(count != tab[0][colonne])
			return (1);
	return (0);
}

int colonne_down(int tab[6][6], int colonne)
{
	int temp;
	int i;
	int count;
	
	temp = 0;
	i = 4;
	count = 0;
	while(i > 0)
	{
		if(tab[i][colonne] > temp)
		{
			count++;
			temp = tab[i][colonne];
		}
		i--;
	}
		if(count != tab[5][colonne])
			return (1);
	return (0);
}

int check_colonne(int tab[6][6], int colonne)
{   
    int i;
    
    i = 1;
    while(i < 5)
    {   
        if(colonne_up(tab, colonne) == 1)
            return (1); 
        if(colonne_down(tab, colonne) == 1)
            return (1);
        i++;
    }
        return (0);
}

