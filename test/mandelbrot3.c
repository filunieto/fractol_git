#include "MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 500
#define HEIGHT 256
#define WIDTH_PIXEL 1
#define HEIGHT_PIXEL 1
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
	img = mlx_new_image(mlx, 1, 1);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
		
	g_img = mlx_new_image(mlx, WIDTH_PIXEL, HEIGHT_PIXEL);
/*
 ** memset Writes "n" bytes of value c 
 ** (as unsigned char) to the string 's'.
void	*memset(void *s, int c, size_t n)
// Set the channels of each pixel in our image to the maximum byte value of 255. 
*/
	memset(g_img->pixels, 64, g_img->width * g_img->height * sizeof(int));
	memset(img->pixels, 32, img->width * img->height * sizeof(int));

	
	mlx_put_pixel(img, 0, 0, 0x00FF00FF); //pone un pixel en la instancia img
	mlx_put_pixel(g_img, 0, 0, 0xFFFF00FF);//pone un pixel en el cuadro g_img

    // start the image at coordinate defined in parameters .
	mlx_image_to_window(mlx, g_img, WIDTH - WIDTH/2, HEIGHT - HEIGHT/3);
	mlx_image_to_window(mlx, img, WIDTH/2, HEIGHT/2);
	mlx_loop_hook(mlx, &hook, mlx); //funciones de teclado
	mlx_loop_hook(mlx, &ft_hook, mlx);// indica el nuevo tamano de la ventana
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
