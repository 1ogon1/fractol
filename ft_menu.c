/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:00:06 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/25 10:54:56 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_menu(t_env *e)
{
	int		c;

	c = 0x009966;
	mlx_string_put(e->mlx, e->win, 1001, 5, c,
			"Press key 1, 2, 3, 4 to select fractals");
	mlx_string_put(e->mlx, e->win, 1001, 30, c,
			"Use arrows for move fractal");
	mlx_string_put(e->mlx, e->win, 1001, 55, c,
			"Pres \"Enter\" and move mouse(Julia");
	mlx_string_put(e->mlx, e->win, 1001, 70, c,
			"or Mandelbrot)");
	mlx_string_put(e->mlx, e->win, 1001, 95, c,
			"Press \"Num+/Num-\" for zoom");
	mlx_string_put(e->mlx, e->win, 1001, 110, c,
			"or you can use the mouse for zoom");
	mlx_string_put(e->mlx, e->win, 1001, 135, c,
			"Press \"+/-\" to change iterations");
	mlx_string_put(e->mlx, e->win, 1001, 160, c,
			"Press \"R/G/B\" on/off colors");
	mlx_string_put(e->mlx, e->win, 1001, 175, c,
			"and press \"n/m\" to change colors");
}
