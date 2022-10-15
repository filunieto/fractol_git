/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:29:03 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 17:31:21 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

int	get_argb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	color(int iteration)
{
	double	inv_iteration;

	inv_iteration = ((double)iteration) / MAX_ITERATIONS;
	if (iteration < MAX_ITERATIONS)
	{
		return (get_argb(0
				, 5 * ((1 - inv_iteration) * pow(inv_iteration, 3)) * 255
				, 10 * ((1 - inv_iteration) * pow(inv_iteration, 4)) * 255
				, 20 * ((1 - inv_iteration) * pow(1 - inv_iteration, 2)
					* pow(inv_iteration, 2)) * 255));
	}
	else
	{
		return (get_argb(-log2(inv_iteration)
				+ 20, -log2(inv_iteration)
				+ 2, 155 + (15 * log2(iteration)), 255));
	}
}
