/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:20:33 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/10 19:45:11 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// Structure for the fractol variables
typedef struct  s_fractol
{
	double  min_r;	// Minimum value of real axis
	double  max_r;	// Maximum value of real axis
	double  min_i;	// Minimum value of imaginary axis
	double  max_i;	// Maximum value of imaginary axis
	double	c_re;
	double	c_im;
	double	j_re;
	double	j_im;
	double	z; //valor absoluto del vector que tendra que ser menor que 4
	double	z_re;
	double	z_im;
	double	k_re;	// Real part of the Julia constant
	double	k_im;	// Imaginary part of the Julia constant
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
	double	mouse_x_pos;
	double	mouse_y_pos;
	t_fractol	*f;
}			t_mlxwin;

#endif