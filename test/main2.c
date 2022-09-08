/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:21:46 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/05 20:36:50 by fnieves-         ###   ########.fr       */
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


mlx_image_t	*g_img;

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

int32_t	main(void)
{

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Register a hook and pass mlx as an optional param.
	// NOTE: Do this before calling mlx_loop! 
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