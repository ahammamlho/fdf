/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:13:43 by lahammam          #+#    #+#             */
/*   Updated: 2022/03/22 10:30:21 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int *fill_line(char **spli, int nbr_rw)
{
	int i;
	int *tab;

	i = 0;
	if (!(tab = (int *)ft_calloc(nbr_rw, sizeof(int))))
		print_exit("error: memory");
	while (spli[i])
	{
		tab[i] = ft_atoi(spli[i]);
		i++;
	}
	return (tab);
}

static int ft_nbr_rw(char **split)
{
	int i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void		free_split(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_free_fdf((void **)&tab[i]);
		i++;
	}
	free(tab);
}

void fill_data(int fd, t_data *data)
{	 
	int i;
	char *str;
	char **spli;
	int  **map;
    
	i = 0;
	if (!(map = (int **)ft_calloc(data->nbr_ln , sizeof(int *))))
		print_exit("error: memory");
	while((str = get_next_line(fd)))
	{
		spli = ft_split(str, ' ');
		if (!spli)
			print_exit("error memory");
		if (!i)
			data->nbr_rw = ft_nbr_rw(spli);
		ft_free_fdf((void **)&str);
		map[i] = fill_line(spli, data->nbr_rw);
		free_split(spli);
		i++;
	}
	ft_free_fdf((void **)&str);
	data->map = map;
}
