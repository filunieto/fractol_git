/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:26:36 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 01:27:15 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"


t_complex	scaling_value(int x, int y, t_view_value *val)
{
	t_complex	c;
	
	val->scale.x = ((val->max.x - val->min.x)/ WIDTH);
	val->scale.y = ((val->max.y - val->min.y)/ HEIGHT);
	c.real = val->min.x + ((double)(x) * val->scale.x);
	c.imm = val->max.y - ((double)(y) * val->scale.y);
	// c.real = (double)(x-(WIDTH/2)) * val->scale.x;
	// c.imm = (double)(y-(HEIGHT/2)) * val->scale.y;
	return (c);
}

// Desde Mandelbrot Jas tratr de copiar las funciones de los colores

int	mandelbrot(t_mlxwin *guide, int x, int y)
{
	t_complex			c;
	t_complex			z;
	t_complex			sum;
	int					iteration;

	z.real = 0;
	z.imm = 0;
	//mandelbrot_view_value(&(data->view));
	c = scaling_value(x, y, &(guide->f->view));
	//printf("x %f , y %f \n", c.real, c.imm);
	iteration = -1;
	while(((z.real * z.real) + (z.imm * z.imm)) < 4 && ++iteration < MAX_ITERATIONS)
	{
		sum.real = (z.real * z.real) - (z.imm * z.imm) + c.real;
		sum.imm =  2 * (z.real * z.imm) + c.imm;
		// if ( z.real == sum.real && z.imm == sum.imm)
		// {
		// 	printf("hit break\n");
		// 	break;
		// }
		z.real = sum.real;
		z.imm = sum.imm;
	}
	return(iteration);
}

int	burning_ship(t_mlxwin *guide, int x, int y)
{
	t_complex			c;
	t_complex			z;
	t_complex			sum;
	int					iteration;

	z.real = 0;
	z.imm = 0;
	//mandelbrot_view_value(&(data->view));
	c = scaling_value(x, y, &(guide->f->view));
	//printf("x %f , y %f \n", c.real, c.imm);
	iteration = -1;
	while(((z.real * z.real) + (z.imm * z.imm)) < 4 && ++iteration < MAX_ITERATIONS)
	{
		sum.real = fabs((z.real * z.real) - (z.imm * z.imm) + c.real);
		sum.imm = fabs(2 * (z.real * z.imm) + c.imm);
		// if ( z.real == sum.real && z.imm == sum.imm)
		// {
		// 	printf("hit break\n");
		// 	break;
		// }
		z.real = sum.real;
		z.imm = sum.imm;
	}
	return(iteration);
	
}

int	colibri(t_mlxwin *guide, int x, int y)
{
	t_complex			c;
	t_complex			z;
	t_complex			sum;
	int					iteration;

	z.real = 0;
	z.imm = 0;
	//mandelbrot_view_value(&(data->view));
	c = scaling_value(x, y, &(guide->f->view));
	//printf("x %f , y %f \n", c.real, c.imm);
	iteration = -1;
	while(((z.real * z.real) + (z.imm * z.imm)) < 4 && ++iteration < MAX_ITERATIONS)
	{
		sum.real = fabs((z.real * z.real) - (z.imm * z.imm) + c.real);
		sum.imm = (2 * (z.real * z.imm) + c.imm);
		// if ( z.real == sum.real && z.imm == sum.imm)
		// {
		// 	printf("hit break\n");
		// 	break;
		// }
		z.real = sum.real;
		z.imm = sum.imm;
	}
	return(iteration);
}
