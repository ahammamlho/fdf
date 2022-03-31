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

#include "fdf.h"

void print_exit(char *msg)
{
	ft_printf("%s \n", msg);
	exit(EXIT_FAILURE);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}


void init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "Hello world!");
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length,
								&data->endian);
}



int	main(int argc, char **argv)
{
	int fd;
	t_data	data;

	if (argc != 2)
		print_exit("Error");
	if (!(fd = open(argv[1], O_RDONLY)))
		print_exit("invalid fd");
	data.nbr_ln = ft_is_mapvalid(fd);
	close(fd);
	if (!(fd = open(argv[1], O_RDONLY)))
		print_exit("invalid fd");
	fill_data(fd , &data);
	init_mlx(&data);
	pixel_put(data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_loop(data.mlx);
}
