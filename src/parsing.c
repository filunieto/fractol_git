/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:49:25 by fnieves-          #+#    #+#             */
/*   Updated: 2022/09/10 14:41:18 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractol.h"


static int	type_cmp(char *av, char *str, char c, char n)
{
	int	i;

	i = -1;
	while (av[++i])
		av[i] = ft_tolower(av[i]);
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

static void	get_set(t_mlxwin  *guide, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		guide->f->fract_id = MANDELBROT;
	else if (type_cmp(av[1], "julia", 'j', '2'))
		guide->f->fract_id = JULIA;
	else
		error_exit(NULL, guide, 1);
}




void	parse_argum(t_mlxwin  *guide, int argc, char **argv)
{
	if (argc < 2)
		error_exit(USAGE, guide, 1); //poner otro mensaje de rror
	if (argc > 5)
		error_exit(USAGE, guide, 1);
	get_set(guide, argv);
	
}


