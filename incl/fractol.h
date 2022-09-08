/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:17:59 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/08 22:39:50 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdio.h> //quitarla
#include <unistd.h>
#include <string.h>
#include <memory.h>
# include "structures.h"
# include "keys.h"



#define MAX_ITERATIONS 80 // Maximum number of iterations
#define WIDTH 800	// Width of the window (in pixels)
#define HEIGHT 800	// Height of the window (in pixels)
#define WIDTH_PIXEL 20
#define HEIGHT_PIXEL 40
#define BPP sizeof(int32_t)

#endif