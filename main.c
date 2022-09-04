/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:21:46 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/04 15:36:13 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 500
#define HEIGHT 256
#define WIDTH_PIXEL 60
#define HEIGHT_PIXEL 128
#define BPP sizeof(int32_t)


mlx_image_t	*g_img;

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


void	hook(void *param)
{
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
	{		
		mlx_close_window(param);
	}
	if (mlx_is_key_down(param, MLX_KEY_UP))
	{		
		g_img->instances[0].y -= 10;
	}	
	if (mlx_is_key_down(param, MLX_KEY_DOWN))
	{		
		g_img->instances[0].y += 25;
	}	
	if (mlx_is_key_down(param, MLX_KEY_LEFT))
	{		
		g_img->instances[0].x -= 5;
	}
	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
	{		
		g_img->instances[0].x += 5;
	}
	printf("pixel altura : %d y anchura : %d \n", g_img->instances[0].y, g_img->instances[0].x);
}

int32_t	main(void)
{
	//mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t	*mlx;
	mlx_image_t* img;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42Flipe", true);
	if (!mlx)
		ft_error();
    // Create a 256x256 image.
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
		
	g_img = mlx_new_image(mlx, WIDTH_PIXEL, HEIGHT_PIXEL);
/*
 ** memset Writes "n" bytes of value c 
 ** (as unsigned char) to the string 's'.
void	*memset(void *s, int c, size_t n)
// Set the channels of each pixel in our image to the maximum byte value of 255. 
*/
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	
	mlx_put_pixel(img, 0, 0, 0xaaaaaaFF); //esta no la entiendo
	mlx_put_pixel(g_img, 0, 0, 0xaaaaaaFF);

    // start the image at coordinate defined in parameters .
	mlx_image_to_window(mlx, g_img, WIDTH - WIDTH/2, HEIGHT - HEIGHT/3);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


// typedef struct	s_data {
// 	mlx_t	*mlx;
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// int32_t	main(void)
// {
// 	mlx_t	*mlx;

// 	t_data data;
// 	data.mlx = mlx_init(WIDTH, HEIGHT, "Flipi", true);
// 	if (!mlx)
// 		exit(EXIT_FAILURE);
// 	// g_img = mlx_new_image(mlx, 64, 128);
// 	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
// 	int i = 0;
// 	int j = 0;
// 	data.img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	g_img = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	while(i<WIDTH)
// 	{
// 		j=0;
// 		while(j < HEIGHT)
// 		{
// 			j++;
// 			mlx_pixel_to_image(mlx, g_img, 250, 125);
// 		}
// 		i++;
// 	}
// 	mlx_image_to_window(mlx, g_img, 250, 125);
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }