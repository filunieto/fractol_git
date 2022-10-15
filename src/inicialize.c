/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:09:50 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 17:32:08 by fnieves-         ###   ########.fr       */
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
	f->c.real = 0;
	f->c.imm = 0;
	f->k.real = -0.79;
	f->k.imm = -0.090000;
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
	null_inicialize_fract(guide->f);
}

void	fractol_inicialize(t_mlxwin *guide)
{
	t_fractol	*f;

	f = guide->f;
	guide->mlx = mlx_init();
	if (!guide->mlx)
		error_exit(ERROR_INIZIALICE, guide, 1);
	f->view.min.x = -2.0;
	f->view.max.x = 2.0;
	f->view.min.y = -2.0;
	f->view.max.y = 2.0;
	guide->win = mlx_new_window(guide->mlx, WIDTH, HEIGHT, "Fract'ol Flipi");
	if (!guide->win)
		error_exit(ERROR_INIZIALICE_WIN, guide, 1);
	guide->img = mlx_new_image(guide->mlx, WIDTH, HEIGHT);
	guide->addr = mlx_get_data_addr(guide->img, &guide->bits_per_pixel,
			&guide->line_length, &guide->endian);
}
