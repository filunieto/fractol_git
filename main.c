/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:28:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 01:37:41 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol.h"

/*
	Explicacion de proyecto.
	Tenemos un cuadrado  de pixeles (900, 900) que hay que transformar en numero complejo (  es C).
	Sabemos la equivalencia de ciertso numeros complejos y algunos pixeles. A partir de ahi 
	hay que ver si ese numero complejo pertenece al set de mandelbrot (dentro o fuera == estable o inestable)
	con la formula Formula : Z = Z * Z + C
	Para saberlo:
	// Formula : Z = Z * Z + c
	//          (where c = cr + ci and Z = zr + zi)
	zr = zr * zr - zi * zi + cr
	zi = 2 * zr * zi + ci
	if ((zr * zr + zi * zi) > 4)
	El numero de iteraciones hasta que se vaya al infinito nos dara los colores (grado de inestabilidad)
    // The number is not part of the set
	
	La funcion Mandelbrot, ira recorriendo cada pixel, calculando C a partir del pixel y comprobando si esta dentro o fuera.
	Dentro tendra color negro fuera tendra otro color. una vex , hecho a cada pixel inicial (x,y) se le asigna el color

	Para sabado:
	intentar la funciond e cambio de color con clik . (d)
uint32_t	generate_colors(int iterations, int max_iterations, t_data *data)
	Corregir los posibles errores de los parametros de Julia
	borrar printf
*/



int	main(int argc, char **argv)
{
	t_mlxwin guide;
	t_fractol f; 

	guide.f = &f;
	null_inicialize(&guide);
	parse_argum(&guide, argc, argv);
	start_printing(&guide);
	//esto es lo que deberia cerrar el programa cuando se cierra la venana. Que significa el paarmtre int x_mask
	//mlx_key_hook(guide.win, hook, &guide);
	//printf("hasta aqui 0/n");
	mlx_key_hook(guide.win, check_keys, &guide);
	////podria usar clean_exit(1, guide) abajo en lugar de close_window?? como pongo 2 parametros;
	mlx_hook(guide.win, EVENT_CLOSE_BTN, 0, close_window,  &guide);
	//hay que anadir la funcion del mouse
	//mlx_mouse_hook(guide.win, &mouse, &guide);
	mlx_hook(guide.win, 4, 0, &hook_mouse, &guide); //Francesco
	mlx_loop(guide.mlx);
}

