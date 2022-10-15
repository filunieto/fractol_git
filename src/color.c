/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:29:03 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 00:34:50 by fnieves-         ###   ########.fr       */
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

int	change_color(t_mlxwin *guide)
{
	if (guide->i < 2)
	{
		if (guide->j < 2)
		{
			if (guide->k < 2)
				return (guide->k++);
			return (guide->j++);
		}
		guide->j = 0;
		guide->k = 0;
		return (guide->i++);
	}
	guide->i = 0;
	return (1);
}





// JAdd

// uint32_t	to_rgb(uint8_t red, uint8_t green, uint8_t blue)
// {
// 	return ((uint32_t)(red << 24 | green << 16 | blue << 8 | 0xFF));
// }

// uint32_t	generate_colors(int iterations, int max_iterations, t_data *data)
// {
// 	double	ratio;
// 	double	ratio_reciprocal;
// 	uint8_t	colors[3];

// 	ratio = (double)iterations / (double)max_iterations;
// 	ratio_reciprocal = 1.0 - ratio;
// 	colors[0] = 9 * (ratio * ratio * ratio) * ratio_reciprocal * 255;
// 	colors[1] = 15 * (ratio * ratio)
// 		* (ratio_reciprocal * ratio_reciprocal) * 255;
// 	colors[2] = 9 * ratio
// 		* (ratio_reciprocal * ratio_reciprocal * ratio_reciprocal) * 255;
// 	return (to_rgb(colors[data->i], colors[data->j], colors[data->k]));
// }

// int	change_color(t_data *data)
// {
// 	if (data->i < 2)
// 	{
// 		if (data->j < 2)
// 		{
// 			if (data->k < 2)
// 				return (data->k++);
// 			return (data->j++);
// 		}
// 		data->j = 0;
// 		data->k = 0;
// 		return (data->i++);
// 	}
// 	data->i = 0;
// 	return (1);
// }
