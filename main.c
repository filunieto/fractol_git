/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:28:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/27 17:15:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol.h"

/*
	Antes  de vacines grecia:
	Se abre los fractales Julia y Mandelbrot
	Se cierran las ventanas corectamente con ESC y el boton rojo.
	He empezado a recoger lo que se pulsa por teclado.
	Desarrollar Mandelbrot hasta el final.: ZOOM, mover ejes y quiza mas colores segun N
	A partir de Madelbrot, hacer Julia
	Preguntas:
	TEngo que usar la funcion mlx_destroy_display(mlx_ptr)?? Parece que cuando la uso no la encuentra: https://aurelienbrabant.fr/blog/getting-started-with-the-minilibx
*/


int hook_mouse(int button, int x, int y, t_mlxwin *guide) // Francesco Zoom scaling function;
{
	t_point	coord;
	float	zoom;
	t_fractol *f;

	f = guide->f;
	
	printf("x: %d, y: %d ", x , y);
	if(button == MOUSE_UP || button == MOUSE_DOWN)
	{
		coord.x = f->view.min.x + (x * f->view.scale.x);
		coord.y = f->view.max.y - (y * f->view.scale.y);
		if(button == MOUSE_UP)
			zoom = 1.2;
		else
			zoom = 0.8;
		(f->view).min.x = coord.x + (f->view.min.x - coord.x) * zoom;
		(f->view).max.x = coord.x + (f->view.max.x - coord.x) * zoom;
		(f->view).min.y = coord.y + (f->view.min.y - coord.y) * zoom;
		(f->view).max.y = coord.y + (f->view.max.y - coord.y) * zoom;
		print_fractal1(guide);
	}
	return (0);
}


int	main(int argc, char **argv)
{
	t_mlxwin guide;
	t_fractol f; 

	guide.f = &f;
	first_inicialize(&guide);
	parse_argum(&guide, argc, argv);
	start_printing(&guide);
	//esto es lo que deberia cerrar el programa cuando se cierra la venana. Que significa el paarmtre int x_mask
	//mlx_key_hook(guide.win, hook, &guide);
	//printf("hasta aqui 0/n");
	mlx_key_hook(guide.win, check_keys, &guide);
	////podria usar clean_exit(1, guide) abajo en lugar de close_window?? como pongo 2 parametros;
	mlx_hook(guide.win, EVENT_CLOSE_BTN, 0, close_window,  &guide);
	//hay que anadir la funcion del mouse
	//mlx_mouse_hook(guide.win, check_mouse_hooks, &guide);
	mlx_hook(guide.win, 4, 0, &hook_mouse, &guide); //Francesco
	mlx_loop(guide.mlx);
}

