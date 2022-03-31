/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valide.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 21:49:58 by lahammam          #+#    #+#             */
/*   Updated: 2022/03/20 21:50:00 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int ft_isexist(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
	
}
static int ft_iscolor(char *str, int i)
{
	int l;

	l = 0;
	if (str[i + 1] && str[i + 1] != '0')
		print_exit("Error map");
	if (str[i + 2] && str[i + 2] != 'x')
		print_exit("Error map");
	i = i + 3;
	while (str[i] && ft_isexist("0123456789ABCDEFabcdef", str[i]))
	{
		i++;
		l++;
	}
	if (l >= 2 && l <= 6)
		return (i);
	else
		return (-1);
}

static int ft_nbr_espace(char *str)
{
	int nbr;
	int i;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i] && str[i] == '-')
			i++;
		if (str[i] && str[i] != '\n' && (str[i] < '0' || str [i] > '9'))
			print_exit("Error : invalid altitude");
		while (str[i] && str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] && str[i] == ',')
		{
			if (ft_iscolor(str, i) == -1)
				print_exit("Error : invalid color");
			else
				i = ft_iscolor(str, i);
		}
		nbr++;
		if (str[i] == '\n')
			break;
		
	}
	return (nbr);
}

int ft_is_mapvalid(int fd)
{
	int line1;
	int line2;
	char *str;
	int nbr_ln;

	str = 0;
	nbr_ln = 0;
	while ((str = get_next_line(fd)))
	{
		line1 = ft_nbr_espace(str);
		ft_free_fdf((void **)&str);
		if (line1 != line2 && nbr_ln != 0)
			print_exit("error : invalid length");
		line2 = line1;
		nbr_ln++;
	}
	if (nbr_ln == 0)
		print_exit("error : error file");
	close(fd);
	return (nbr_ln);
}