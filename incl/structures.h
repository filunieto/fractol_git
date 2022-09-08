/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:20:33 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/08 22:25:00 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

// Structure for the fractol variables
typedef struct  s_fractol
{
	void	*mlx;	// Pointer to mlx
	void	*win;	// Pointer to window
	double  min_r;	// Minimum value of real axis
	double  max_r;	// Maximum value of real axis
	double  min_i;	// Minimum value of imaginary axis
	double  max_i;	// Maximum value of imaginary axis
}   t_fractol;


#endif