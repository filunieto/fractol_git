/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 21:29:03 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/27 21:29:42 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

static int	get_rgb(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

int	color(int iteration)
{
	double inv_iteration = (double)iteration / MAX_ITERATIONS;
	if (iteration < MAX_ITERATIONS)
	{
	//return (get_rgb( 50 ,9 * (1 - inv_iteration) * pow(inv_iteration, 3) * 255 , 15 * pow((1 - inv_iteration), 2) * pow(inv_iteration, 2) * 255, 15 * pow((1 - inv_iteration), 3) * inv_iteration * 255));
	//return (get_rgb( -log2(inv_iteration) * 255 / 7 ,(20 * (cos(255/5 * M_PI + M_PI)) + 1) / 2 , 155 + (15*sin(iteration)), 255));
	//return (get_rgb( -log2(inv_iteration) + 20, -log2(inv_iteration) + 2 , 155 + (15*log2(iteration)), 255)); // shade of cyan;
	return (get_rgb( -log2(inv_iteration) + 20, -log2(inv_iteration) + 2 , 155 + (15*log2(iteration)), 255)); // shade of cyan;
	//return (get_rgb( -log2(inv_iteration) + 20, -log2(inv_iteration) + 2 , 155 + (15*log2(iteration)), 100));	//pale green;
	//return (get_rgb( -log2(inv_iteration) + 20, 100 , 155 + (15*log2(iteration)), -log2(inv_iteration) + 2));	//acid yellow;
	//return (get_rgb( -log2(inv_iteration) + 20, 100 , 155 + (15*log2(iteration)), (log(iteration) - log(50)) / (log(MAX_ITERATION) - log(50)) + 2));
	}
	else 
	//return (get_rgb( -log2(iteration) * 255 / 7 , 188, 194, 255));
	return (get_rgb(255, 188, 194, 255));
}