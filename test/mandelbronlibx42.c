/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbronlibx42.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:21:46 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/06 17:45:25 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "MLX42/include/MLX42/MLX42.h"
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
	mlx_t	*mlx;	// Pointer to mlx
	void	*win;	// Pointer to window . ESTA creo que no aplicable
	mlx_image_t* img; //esta es mia para la imagen
	double  min_r;	// Minimum value of real axis
	double  max_r;	// Maximum value of real axis
	double  min_i;	// Minimum value of imaginary axis
	double  max_i;	// Maximum value of imaginary axis
}   t_fractol;

void	mandelbrot(t_fractol *f, int x, int y, double cr, double ci);



// 'Encodes' four individual bytes into an int.
int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// Get the red channel.
int get_r(int rgba)
{
    // Move 3 bytes to the right and mask out the first byte.
    return ((rgba >> 24) & 0xFF);
}

// Get the green channel.
int get_g(int rgba)
{
    // Move 2 bytes to the right and mask out the first byte.
    return ((rgba >> 16) & 0xFF);
}

// Get the blue channel.
int get_b(int rgba)
{
    // Move 1 byte to the right and mask out the first byte.
    return ((rgba >> 8) & 0xFF);
}

// Get the alpha channel.
int get_a(int rgba)
{
    // Move 0 bytes to the right and mask out the first byte.
    return (rgba & 0xFF);
}

// Exit the program as failure.
static void ft_error(void)
{
	printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;
	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}


// void	hook(void *param)
// {
// 	mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t	*mlx;

// 	mlx = param;
// 	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
// 	{		
// 		mlx_close_window(param);
// 	}
// 	if (mlx_is_key_down(param, MLX_KEY_UP))
// 	{		
// 		img->instances[0].y -= 10;
// 	}	
// 	if (mlx_is_key_down(param, MLX_KEY_DOWN))
// 	{		
// 		img->instances[0].y += 25;
// 	}	
// 	if (mlx_is_key_down(param, MLX_KEY_LEFT))
// 	{		
// 		img->instances[0].x -= 5;
// 	}
// 	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
// 	{		
// 		img->instances[0].x += 5;
// 	}
// 	printf("pixel altura : %d y anchura : %d \n", img->instances[0].y, img->instances[0].x);
// }

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
	//esto es lo que tengo que modificar de alguna manera
	if (is_in_set == 1)
		mlx_put_pixel(f->img, x, y, 0x000000);
	else
		mlx_put_pixel(f->img,  x, y, 0xFFFFFF);
}

int32_t	main(void)
{
	//mlx_set_setting(MLX_MAXIMIZED, true);
	t_fractol f; // Structure for fract'ol variables

	//mlx_t	*mlx;
	//mlx_image_t* img;
	f.mlx = mlx_init(WIDTH, HEIGHT, "MLX42Flipe", true);
	if (!f.mlx)
		ft_error();
    // Create a 256x256 image.
	f.img = mlx_new_image(f.mlx, WIDTH_PIXEL, HEIGHT_PIXEL);

	if (!f.img || (mlx_image_to_window(f.mlx, f.img, 0, 0) < 0))
		ft_error();
		
/*
 ** memset Writes "n" bytes of value c 
 ** (as unsigned char) to the string 's'.
void	*memset(void *s, int c, size_t n)
// Set the channels of each pixel in our image to the maximum byte value of 255. 
*/

	memset(f.img->pixels, 240, f.img->width * f.img->height * sizeof(int));

	
	mlx_put_pixel(f.img, 10, 25, 0x00FF00FF); //pone un pixel en la instancia img./ chiquitio verde
	//mlx_put_pixel(g_img, 0, 0, 0xFFFF00FF);//pone un pixel en el cuadro g_img

    // start the image at coordinate defined in parameters .
	//mlx_image_to_window(f.mlx, g_img, WIDTH - WIDTH/2, HEIGHT - HEIGHT/3);
	mlx_image_to_window(f.mlx, f.img, WIDTH-200, HEIGHT-150);
	//mlx_loop_hook(f.mlx, &hook, &f.mlx); //funciones de teclado
	mlx_loop_hook(f.mlx, &ft_hook, f.mlx);// indica el nuevo tamano de la ventana
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (EXIT_SUCCESS);
}
