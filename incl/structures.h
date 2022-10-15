/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:20:33 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 12:37:39 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_complex
{
	double		real;
	double		imm;
}				t_complex;

/*
** max and min axes (x,y == r, i) values
** scale >>> will allows us to zoom from the position of the mouse
*/
typedef struct	s_view_value
{
	t_point		min;
	t_point		max;
	t_point		scale;
	double		zoom;
}				t_view_value;

// Structure for the fractol variables.
typedef struct  s_fractol
{
	double			val_x;
	double			val_y;
	t_complex		c;
	t_complex		k;
	t_view_value	view;
	int				fract_id;
}	t_fractol;

typedef struct s_mlxwin
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int i; //borrar estas 3 variables?
	int j;
	int k;
	t_fractol	*f;
}			t_mlxwin;

#endif