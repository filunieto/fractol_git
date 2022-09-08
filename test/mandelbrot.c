#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>   
#define MAX_ITERATIONS 80 // Maximum number of iterations
#define WIDTH 900	// Width of the window (in pixels)
#define HEIGHT 900	// Height of the window (in pixels)

// Exit the program as failure.
static void ft_error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Structure for the fractol variables
typedef struct  s_fractolz
{
	mlx_t	*mlx;	// Pointer to mlx
	void	*win;	// Pointer to window . ESTA creo que no aplicable
	mlx_image_t* img;
	double  min_r;	// Minimum value of real axis
	double  max_r;	// Maximum value of real axis
	double  min_i;	// Minimum value of imaginary axis
	double  max_i;	// Maximum value of imaginary axis
}   t_fractol;

void	mandelbrot(t_fractol *f, int x, int y, double cr, double ci)
{
	int	n;	// Number of iterations
	double	zr;	// Real part of Z
	double	zi;	// Imaginary part of Z
	double	tmp;	// Temporary variable
	// Variable to determine if a number is in the set or not:
	int	is_in_set; 

	zr = 0;
	zi = 0;
	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		// As long as we're not at the maximum number of iterations,
		// we iterate
		if ((zr * zr + zi * zi) > 4.0)
		{
			// If the absolute value of Z exceeds 2
			// (zr * zr + zi * zi) > 4.0 == sqrt(zr * zr + zi * zi) > 2
			is_in_set = 0;
			// We flag that this number tends toward infinity, 
			// and is therefore not part of the set
			// and we stop iterating
			break ;
		}
		// Calculate the Mandelbrot formula for the next iteration
		tmp = 2 * zr * zi + ci;
		zr = zr * zr - zi * zi + cr;
		zi = tmp;
	}
	// If the number is part of the Mandelbrot set,
	// set the pixel to black, otherwise to white
	if (is_in_set == 1)
		mlx_put_pixel(f->img, x, y, 0x000000);
	else
		mlx_put_pixel(f->img,  x, y, 0xFFFFFF);
}

void	draw_fractal(t_fractol *f)
{
	// x and y coordinates of the pixel:
	int	x; // column
	int	y; // line
	// to map the x and y coordinates of the pixel to a
	// complex number:
	double	pr; // real part of the complex number of the pixel
	double	pi; // imaginary part of the complex number of the pixel

	// Loop over each line and column of the window
	// to check each pixels
	y = -1;
	while (++y < HEIGHT) // line loop
	{
		x = -1;
		while (++x < WIDTH) // column loop
		{
			// Find pixel[x, y]'s corresponding complex number
			pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			pi = f->min_i + (double)y * (f->max_i - f->min_i) / HEIGHT;
			// Evaluate it and set this pixel's color
			mandelbrot(f, x, y, pr, pi);
		}
	}
}

int	main(void)
{
	t_fractol f; // Structure for fract'ol variables

	f.mlx = mlx_init(WIDTH, HEIGHT, "Mandel1", true); // Initialize mlx
	if (!f.mlx)
		ft_error();
	f.img = mlx_new_image(f.mlx, 1, 1);
	if (!f.img || (mlx_image_to_window(f.mlx, f.img , 0, 0) < 0))
		ft_error();
	// Value of complex numbers on left edge of window:
	f.min_r = -2.0;
	// Value of complex numbers on right edge of window:
	f.max_r = 1.0;
	// Value of complex numbers on top edge of window:
	f.min_i = -1.5;
	// Value of complex numbers on bottom edge of window:
	f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	
	// // Create window: NO APLICA
	//f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract'ol test");

	// Start fractal calculation:
	draw_fractal(&f);

	
	// mlx's infinite loop:
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);

}