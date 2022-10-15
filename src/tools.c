/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 23:39:03 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 13:28:45 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	check_keys(int keycode, t_mlxwin  *guide)
{
	if (keycode == ESC)
		clean_exit(1, guide);
	if (keycode == UP)
		move_up(guide);
	else if (keycode == DOWN)
		move_down(guide);
	else if (keycode == LEFT)
		move_left(guide);
	else if (keycode == RIGHT)
		move_right(guide);
	return (0);
}

int hook_mouse(int button, int x, int y, t_mlxwin *guide)
{
	t_point	coord;
	float	zoom;
	t_fractol *f;

	f = guide->f;
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
		print_fractal(guide);
	}
	return (0);
}
