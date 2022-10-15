/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 00:28:00 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 17:42:06 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	move_up(t_mlxwin *guide)
{
	double	diff;

	diff = guide->f->view.max.y - guide->f->view.min.y;
	guide->f->view.min.y -= diff / 50;
	guide->f->view.max.y -= diff / 50;
	print_fractal(guide);
}

void	move_down(t_mlxwin *guide)
{
	double	diff;

	diff = guide->f->view.max.y - guide->f->view.min.y;
	guide->f->view.min.y += diff / 50;
	guide->f->view.max.y += diff / 50;
	print_fractal(guide);
}

void	move_left(t_mlxwin *guide)
{
	double	diff;

	diff = guide->f->view.max.x - guide->f->view.min.x;
	guide->f->view.min.x -= diff / 50;
	guide->f->view.max.x -= diff / 50;
	print_fractal(guide);
}

void	move_right(t_mlxwin *guide)
{
	double	diff;

	diff = guide->f->view.max.x - guide->f->view.min.x;
	guide->f->view.min.x += diff / 50;
	guide->f->view.max.x += diff / 50;
	print_fractal(guide);
}
