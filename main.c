/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:28:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/11 00:53:46 by fnieves-         ###   ########.fr       */
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
*/

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
	mlx_key_hook(guide.win, check_keys, &guide);
	////podria usar clean_exit(1, guide) abajo en lugar de close_window?? como pongo 2 parametros;
	mlx_hook(guide.win, EVENT_CLOSE_BTN, 0, close_window,  &guide);
	//hay que anadir la funcion del mouse
	//mlx_mouse_hook(guide.win, check_mouse_hooks, &guide);
	mlx_loop(guide.mlx);
	
}

