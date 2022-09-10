# include "lib/minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <memory.h>
#define MAX_ITERATIONS 80 // Maximum number of iterations
#define WIDTH 900	// Width of the window (in pixels)
#define HEIGHT 900	// Height of the window (in pixels)
#define WIDTH_PIXEL 20
#define HEIGHT_PIXEL 40
#define BPP sizeof(int32_t)

typedef struct  s_fractol
{
	void	*mlx;
	void	*win;
	double  min_r;
	double  max_r;
	double  min_i;
	double  max_i;
	double	kr;	// Real part of the Julia constant
	double	ki;	// Imaginary part of the Julia constant
}   t_fractol;

void	julia(t_fractol *f, int x, int y, double zr, double zi)
{
	// Here, zr and zi are the values of the real and imaginary
	// parts of our pixel's complex number, unlike the
	// Mandelbrot formula that uses zr = 0 and zi = 0
	int		n;
	double	tmp;
	int		is_in_set;

	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		// ki and kr are predefined in the structure, but apart from
		// that, the formula is exactly the same as Mandelbrot
		tmp = 2 * zr * zi + f->ki;
		zr = zr * zr - zi * zi + f->kr;
		zi = tmp;
	}
	if (is_in_set == 1)
		mlx_pixel_put(f->mlx, f->win, x, y, 0x000000);
	else
		mlx_pixel_put(f->mlx, f->win, x, y, 0xFFFFFF);
}

void	draw_fractal(t_fractol *f)
{
	int		x;
	int		y;
	double	pr;
	double	pi;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			// We pass Julia the real and imaginary parts
			// converted from pixel coordinates, which will be
			// used as the initial value of Z.
			julia(f, x, y, pr, pi);
		}
	}
}

int	main(void)
{
	t_fractol f;

	f.mlx = mlx_init();
	f.min_r = -2.0;
	f.max_r = 1.0;
	f.min_i = -1.5;
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	// For Julia, we define the real and imaginary parts of 
	// the constant K
	f.kr = -0.766667;
	f.ki = -0.090000;
	f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract'ol test");
	draw_fractal(&f);
	mlx_loop(f.mlx);
}
