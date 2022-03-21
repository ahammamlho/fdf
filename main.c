/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:10:08 by lahammam          #+#    #+#             */
/*   Updated: 2022/03/20 18:10:12 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <mlx.h>
#include "fdf.h"


void print_exit(char *msg)
{
	ft_printf("%s \n", msg);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		print_exit("Error");
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		print_exit("invalid fd");
	ft_is_mapvalid(fd);
	close(fd);
}
