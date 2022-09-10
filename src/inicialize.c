/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:09:50 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/10 19:51:25 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void static	first_inicialize_fract(t_fractol *f)
{
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->c_re = 0;
	f->c_im = 0;
	f->j_re = 0;
	f->j_im = 0;
	f->z = 0;
	f->z_re = 0;
	f->z_im = 0;
	f->k_re = -0.766667;
	f->k_im = -0.090000;
	f->fract_id = 0;
}

void	first_inicialize(t_mlxwin *guide)
{
	guide->mlx = NULL;
	guide->win = NULL;
	guide->img = NULL;
	
	guide->addr = NULL;
	guide->bits_per_pixel = 0;
	guide->line_length = 0;
	guide->endian = 0;
	guide->mouse_x_pos = 0;
	guide->mouse_y_pos = 0;
	
	first_inicialize_fract(guide->f);
}



void	fractol_inicialize(t_mlxwin *guide)
{
	t_fractol *f;
	
	f = guide->f;
	guide->mlx = mlx_init();
	if(!guide->mlx)
		error_exit(ERROR_INIZIALICE, guide, 1);
	f->min_r = -2.0;
	f->max_r = 1.0;
	f->min_i = -1.5;
	f->max_i = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	guide->win = mlx_new_window(guide->mlx, WIDTH, HEIGHT, "Fract'ol Flipi");
	if(!guide->win)
		error_exit(ERROR_INIZIALICE_WIN, guide, 1);
	guide->img = mlx_new_image(guide->mlx, WIDTH, HEIGHT);
	guide->addr = mlx_get_data_addr(guide->img, &guide->bits_per_pixel,
			&guide->line_length, &guide->endian);

}
