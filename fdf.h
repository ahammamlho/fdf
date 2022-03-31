

#ifndef FDF_H
#define FDF_H
#include <stdio.h>
# include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	int				nbr_ln;
	int				nbr_rw;
	int				**map;

	int				x;
	int				y;
	int				z;
	int				px;
	int				py;
	int				height;
	int				color;
}	t_data;

int ft_is_mapvalid(int file);
void print_exit(char *msg);
void fill_data(int fd, t_data *data);
void	ft_free_fdf(void **str);
void pixel_put(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
#endif