/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:09:50 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/12 11:40:40 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void static	null_inicialize_fract(t_fractol *f)
{
	f->view.min.x = 0;
	f->view.min.y = 0;
	f->view.max.x = 0;
	f->view.max.y = 0;
	f->view.scale.x = 0;
	f->view.scale.y = 0;
	f->val_x = 0;
	f->val_y = 0;
	// f->min_r = 0;
	// f->max_r = 0;
	// f->min_i = 0;
	// f->max_i = 0;
	f->c.real = 0;
	f->c.imm = 0;
	// f->c_re = 0;
	// f->c_im = 0;
	f->j.real = 0;
	f->j.imm = 0;
	// f->j_re = 0;
	// f->j_im = 0;
	f->z_mod = 0;
	f->z_complex.real = 0;
	f->z_complex.imm = 0;
	f->k.real = -0.766667;
	f->k.imm = -0.090000;
	// f->k_re = -0.766667;
	// f->k_im = -0.090000;
	f->fract_id = 0;
}

void	null_inicialize(t_mlxwin *guide)
{
	guide->mlx = NULL;
	guide->win = NULL;
	guide->img = NULL;
	
	guide->addr = NULL;
	guide->bits_per_pixel = 0;
	guide->line_length = 0;
	guide->endian = 0;
	// guide->mouse_x_pos = 0;
	// guide->mouse_y_pos = 0;
	
	null_inicialize_fract(guide->f);
}



void	fractol_inicialize(t_mlxwin *guide)
{
	t_fractol *f;
	
	f = guide->f;
	guide->mlx = mlx_init();
	if(!guide->mlx)
		error_exit(ERROR_INIZIALICE, guide, 1);
	f->view.min.x = -2.0;
	f->view.max.x = 2.0;
	f->view.min.y = -2.0;
	f->view.max.y = 2.0;
	//f->view.max.y = f->min_i + (f->max_r - f->min_r) * HEIGHT / WIDTH; si l aventana no es un cadrado

	guide->win = mlx_new_window(guide->mlx, WIDTH, HEIGHT, "Fract'ol Flipi");
	if(!guide->win)
		error_exit(ERROR_INIZIALICE_WIN, guide, 1);
	guide->img = mlx_new_image(guide->mlx, WIDTH, HEIGHT);
	guide->addr = mlx_get_data_addr(guide->img, &guide->bits_per_pixel,
			&guide->line_length, &guide->endian);

}
