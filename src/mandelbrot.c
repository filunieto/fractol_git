/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:26:36 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 17:40:35 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

t_complex	scaling_value(int x, int y, t_view_value *val)
{
	t_complex	c;

	val->scale.x = ((val->max.x - val->min.x) / WIDTH);
	val->scale.y = ((val->max.y - val->min.y) / HEIGHT);
	c.real = val->min.x + ((double)x * val->scale.x);
	c.imm = val->max.y - ((double)y * val->scale.y);
	return (c);
}

int	mandelbrot(t_mlxwin *guide, int x, int y)
{
	t_complex			c;
	t_complex			z;
	t_complex			sum;
	int					iteration;

	z.real = 0;
	z.imm = 0;
	c = scaling_value(x, y, &(guide->f->view));
	iteration = -1;
	while (((z.real * z.real) + (z.imm * z.imm))
		< 4 && ++iteration < MAX_ITERATIONS)
	{
		sum.real = (z.real * z.real) - (z.imm * z.imm) + c.real;
		sum.imm = 2 * (z.real * z.imm) + c.imm;
		z.real = sum.real;
		z.imm = sum.imm;
	}
	return (iteration);
}

int	burning_ship(t_mlxwin *guide, int x, int y)
{
	t_complex			c;
	t_complex			z;
	t_complex			sum;
	int					iteration;

	z.real = 0;
	z.imm = 0;
	c = scaling_value(x, y, &(guide->f->view));
	iteration = -1;
	while (((z.real * z.real) + (z.imm * z.imm))
		< 4 && ++iteration < MAX_ITERATIONS)
	{
		sum.real = fabs((z.real * z.real) - (z.imm * z.imm) + c.real);
		sum.imm = fabs(2 * (z.real * z.imm) + c.imm);
		z.real = sum.real;
		z.imm = sum.imm;
	}
	return (iteration);
}

int	colibri(t_mlxwin *guide, int x, int y)
{
	t_complex			c;
	t_complex			z;
	t_complex			sum;
	int					iteration;

	z.real = 0;
	z.imm = 0;
	c = scaling_value(x, y, &(guide->f->view));
	iteration = -1;
	while (((z.real * z.real) + (z.imm * z.imm))
		< 4 && ++iteration < MAX_ITERATIONS)
	{
		sum.real = fabs((z.real * z.real) - (z.imm * z.imm) + c.real);
		sum.imm = (2 * (z.real * z.imm) + c.imm);
		z.real = sum.real;
		z.imm = sum.imm;
	}
	return (iteration);
}
