/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:28:14 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 18:04:06 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/fractol.h"

/*
	Resume of the project:
	We have a square of pixels (ej: 900, 900) to be transformed
	into a complex plane ( C).
	We know the equivalence of some complex numbers and
	some pixels. By trigonometry we calculate each complex point.
	Then we check if this complex number belongs to
	the mandelbrot set (inside or outside == stable or unstable).
	with the formula Formula : Z = Z * Z + C
	To find out:
		Formula : Z = Z * Z + c
	(where c = cr + ci and Z = zr + zi)
	zr = zr * zr - zi * zi + cr
	zi = 2 * zr * zi + ci
	if ((zr * zr + zi * zi) > 4)
	The number of iterations until it goes to infinity
	will give us the colours (degree of instability)
*/

/*
	atexit(check_leaks);
*/
void	check_leaks(void)
{
	system("leaks fractol");
}

int	main(int argc, char **argv)
{
	t_mlxwin	guide;
	t_fractol	f;

	guide.f = &f;
	null_inicialize(&guide);
	parse_argum(&guide, argc, argv);
	fractol_inicialize(&guide);
	print_fractal(&guide);
	mlx_key_hook(guide.win, &check_keys, &guide);
	mlx_hook(guide.win, EVENT_CLOSE_BTN, 0, close_window, &guide);
	mlx_hook(guide.win, 4, 0, &hook_mouse, &guide);
	mlx_loop(guide.mlx);
	return (0);
}
