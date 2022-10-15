/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:20:33 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/14 22:56:36 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct	s_color_palette
{
	int	red;
	int	green;
	int	blue;
	int	t;
}				t_color_palette;

typedef struct	s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct	s_complex //podria anadir en esta estructura los valores polares en funcion de los cartesianos?
{
	double		real;
	double		imm;
}				t_complex;

typedef struct	s_view_value
{
	t_point		min; //min_r and min_i
	t_point		max;
	t_point		scale;
	double		zoom;
}				t_view_value;

/*
** Return value from fractal iterations
*/
typedef struct	s_pixel
{
	t_complex	coordinates;
	int			divergence_index;
}				t_pixel;

// Structure for the fractol variables. Borrar lo que nonecesite
typedef struct  s_fractol
{
	t_view_value view;
	double		val_x;
	double		val_y;
	// double  min_r;	// Minimum value of real axis
	// double  max_r;	// Maximum value of real axis
	// double  min_i;	// Minimum value of imaginary axis
	// double  max_i;	// Maximum value of imaginary axis
	t_complex c;
	// double	c_re;
	// double	c_im;
	t_complex j;
	// double	j_re;
	// double	j_im;
	t_complex z_complex;
	double	z_mod; //valor absoluto del vector que tendra que ser menor que 4
	// double	z_re;
	// double	z_im;
	t_complex	k;
	// double	k_re;	// Real part of the Julia constant
	// double	k_im;	// Imaginary part of the Julia constant
	int		fract_id; //identificacion de fractal
}	t_fractol;

typedef struct s_mlxwin
{
	void	*mlx;	// Pointer to mlx
	void	*win;	// Pointer to window
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int i;
	int j;
	int k;
	// double	mouse_x_pos;
	// double	mouse_y_pos;
	t_fractol	*f;
}			t_mlxwin;

#endif