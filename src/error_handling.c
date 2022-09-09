/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 19:45:41 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/09 20:23:45 by fnieves-         ###   ########.fr       */
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
	//anadir el free de todo si es necesario segun miriam 
}

/* 
	Destroys the window, the MLX image and the MLX instance,
	Para destruir ventanas e instancias usa funciones de libreria
	
	estas verificaciones no son neceasarias ya que hacer un free
	 de algo NULL no dara problemas. Importante inicizalizar a NULL
	if (!f)  >>> este if no es necesartio
		exit(exit_code);
*/
void	clean_exit(int exit_code, t_mlxwin  *guide) //para que esta funcion
{
	if (!guide)  
		exit(exit_code);
	// if (guide->palette)
	// 	free(guide->palette);
	if (guide->img)
		mlx_destroy_image(guide->mlx, guide->img); //esta funcion es de libreria
	if (guide->win && guide->mlx) //esta condicion si es necesaria
		mlx_destroy_window(guide->mlx, guide->win);

	// Atencion aqui
	// if (guide->mlx) //condicion necesaria 
	// {
	// 	mlx_loop_end(guide->mlx);
	// 	mlx_destroy_display(guide->mlx);
	// 	free(guide->mlx);
	// }
	exit(exit_code);
}