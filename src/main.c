/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:28:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/09 20:11:20 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

// int	hook(int key, void *param)
// {
// 	t_fractol *f;

// 	printf("key : %d\n", key);
// 	f = param;
// 	if (key == MLX_KEY_ESCAPE)
// 	{		
// 		mlx_destroy_window(f->mlx, f->win);
// 	}
// 	return (0);
// }




int	main(int argc, char **argv)
{
	t_mlxwin guide;
	t_fractol f; // Structure for fract'ol variables

	guide.f = &f;
	first_inicialize(&guide);
	parse_argum(&guide, argc, argv);
	start_printing(&guide);
	// //todo lo de abajo pasarlo su funcion
	// //inicializa los valores 
	// f.mlx = mlx_init(); // Initialize mlx
	// // Value of complex numbers on left edge of window:
	// f.min_r = -2.0;
	// // Value of complex numbers on right edge of window:
	// f.max_r = 1.0;
	// // Value of complex numbers on top edge of window:
	// f.min_i = -1.5;
	// // Value of complex numbers on bottom edge of window: //verificar este calculo
	// f.max_i = f.min_i + (f.max_r - f.min_r) * HEIGHT / WIDTH;
	// // Create window:
	// f.win = mlx_new_window(f.mlx, WIDTH, HEIGHT, "Fract'ol Flipi");
	// Start fractal calculation:
	//draw_fractal(&f);
	
	// mlx's infinite loop:
	//mlx_key_hook(guide.win, &hook, &guide); //funciones de teclado
	mlx_loop(guide.mlx);
}

