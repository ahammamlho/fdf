

#ifndef FDF_H
#define FDF_H
#include <stdio.h>
# include <fcntl.h>
#include <stdlib.h>
#include "gnl/get_next_line.h"
#include "ft_printf/ft_printf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int ft_is_mapvalid(int file);
void print_exit(char *msg);


#endif