
#include "../fdf.h"



void tracerSegment(double x1, double y1, double x2, double y2)
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
		// tracerPixel(x1, y1);
		x1 = x1 + 1;
		e = e - dy;
		if (e <= 0)
		{
			y1 = y1 + 1;
			e = e + dx;
		}
	}
}


// tracerSegment(0.0, 0.0, 10.0, 10.0);
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
//     // int i = 0;
// 	// while (i < 200)
// 	// {
// 	// 	my_mlx_pixel_put(&img, 10*i, 500, 0x00FF0000);
// 	// 	i++;
// 	// }

// 	// -------

// 	double x1 = 0; double y1 = 0;
// 	double x2 = 1000; double y2 = 1000;
// 	double dx;
// 	double dy;
// 	double e;
	
// 	e = x2 - x1;
// 	dx = 2 * e;
// 	dy = (y2 - y1) * 2;
// 	while (x1 <= x2)
// 	{
// 		printf("x1 = %f; y1 = %f\n",x1,y1);
// 		my_mlx_pixel_put(&img, x1, y1, 0x00FF0000);
// 		x1 = x1 + 1;
// 		e = e - dy;
// 		if (e <= 0)
// 		{
// 			y1 = y1 + 1;
// 			e = e + dx;
// 		}
// 	}

// 	//------------
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);








