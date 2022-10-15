/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:45:41 by fnieves-          #+#    #+#             */
/*   Updated: 2022/10/15 17:31:51 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"

void	error_exit(char *message, t_mlxwin *guide, int exit_code)
{
	if (message == NULL)
		write(1, USAGE, ft_strlen(USAGE));
	else
		write(1, message, ft_strlen(message));
	clean_exit(exit_code, guide);
}

/* 
	Destroys the window, the MLX image and the MLX instance,
*/
void	clean_exit(int exit_code, t_mlxwin *guide)
{
	exit_code = 0;
	guide->f = NULL;
	if (guide->mlx != NULL)
	{
		mlx_destroy_window(guide->mlx, guide->win);
		mlx_destroy_image(guide->mlx, guide->img);
	}
	exit(exit_code);
}

void	close_window(t_mlxwin *guide)
{
	clean_exit(1, guide);
}
