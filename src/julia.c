/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:26:40 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/10 14:54:17 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	julia(t_mlxwin *guide, int x, int y, double zr, double zi)
{
	// Here, zr and zi are the values of the real and imaginary
	// parts of our pixel's complex number, unlike the
	// Mandelbrot formula that uses zr = 0 and zi = 0
	int		n;
	double	tmp;
	int		is_in_set;

	n = -1;
	is_in_set = 1;
	while (++n < MAX_ITERATIONS)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			is_in_set = 0;
			break ;
		}
		// ki and kr are predefined in the structure, but apart from
		// that, the formula is exactly the same as Mandelbrot
		tmp = 2 * zr * zi + guide->f->k_im;
		zr = zr * zr - zi * zi +  guide->f->k_re;
		zi = tmp;
	}
	if (is_in_set == 1)
		mlx_pixel_put(guide->mlx, guide->win, x, y, 0x000000);
	else
		mlx_pixel_put(guide->mlx, guide->win, x, y, 0xFFFFFF);
}

