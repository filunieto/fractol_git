/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:39:03 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 01:35:33 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	check_keys(int keycode, t_mlxwin  *guide)
{
	if (keycode == ESC)
		clean_exit(1, guide);
	printf("key : %d\n", keycode);
	if (keycode == UP)
		move_up(guide);
	else if (keycode == DOWN)
		move_down(guide);
	else if (keycode == LEFT)
		move_left(guide);
	else if (keycode == RIGHT)
		move_right(guide);
	if(keycode == Q)
	{
		change_color(guide);
		print_fractal1(guide);
	}
	return (0);
}

int hook_mouse(int button, int x, int y, t_mlxwin *guide) // Francesco Zoom scaling function;
{
	t_point	coord;
	float	zoom;
	t_fractol *f;

	f = guide->f;
	
	printf("x: %d, y: %d ", x , y);//esta funcion hay que quiatrla, que por cierto no funcona muy bien 
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
	// if(button == LEFT_CLICK)
	// {
	// 	change_color(guide);
	// 	print_fractal1(guide);
	// }
	return (0);
}


// Funcion de hellen par aeventios del raton
// int	mouse(int button, t_mlxwin  *guide)
// {
// 	if (button == SCROLL_UP)
// 		zoom(x, y, fr, ZOOM);
// 	else if (button == SCROLL_DOWN)
// 		zoom(x, y, fr, 1 / ZOOM);
// 	else if (button == RIGHT_CLICK)
// 		switch_to_julia(fr, (double) x, (double) y);
// 	else if (button == MOUSE_WHEEL)
// 		print_coordinates(fr, (double) x, (double) y);
// 	return (0);
// }
