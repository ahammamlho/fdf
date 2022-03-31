/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lahammam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:08:34 by lahammam          #+#    #+#             */
/*   Updated: 2022/03/22 18:08:35 by lahammam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void tracerSegment(double x1, double y1, double x2, double y2, t_data *data)
{
	double dx;
	double dy;
	double e;
	
	e = x2 - x1;
	dx = 2 * e;
	dy = (y2 - y1) * 2;
	while (x1 <= x2)
	{
		printf("x1 = %f; y1 = %f\n",x1,y1);
		my_mlx_pixel_put(data, x1, x2, 0x00FF0000);
		x1 = x1 + 1;
		e = e - dy;
		if (e <= 0)
		{
			y1 = y1 + 1;
			e = e + dx;
		}
	}
}

void pixel_put(t_data *data)
{
	int x;
	int y;

	x = 0;
	y = 0;
	// while (x < data->nbr_rw)
	// {
	// 	while (y < data->nbr_ln)
	// 	{
			tracerSegment(x, y , x + 1, y + 1, data);
	// 		y++;
	// 	}
	// 	y = 0;
	// 	x++;
	// }
	
}