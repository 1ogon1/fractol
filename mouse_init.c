/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkonoval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:46:34 by rkonoval          #+#    #+#             */
/*   Updated: 2017/03/25 11:15:09 by rkonoval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (x >= 0 && x < 1000 && y >= 0 && y < 800 && (button == 4 || button == 5))
	{
		if (button == 4)
		{
			e->change->ch_zoom *= 1.1;
			e->change->ch_mvy += (y - 800 / 2) / (800 * 2.2) /
				e->change->ch_zoom;
			e->change->ch_mvx += (x - 1000 / 2) / (1000 * 2.2) /
				e->change->ch_zoom;
		}
		else if (button == 5)
		{
			if (ft_strcmp(e->c, "b") == 0 && e->change->ch_zoom <= 0.564474)
				e->change->ch_zoom = 0.564474;
			e->change->ch_zoom /= 1.1;
			e->change->ch_mvy += (y - 800 / 2) / (800 * 2.2) /
				e->change->ch_zoom;
			e->change->ch_mvx += (x - 1000 / 2) / (1000 * 2.2) /
				e->change->ch_zoom;
		}
		ft_replaceimg(e);
	}
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	float	rx;
	float	ry;

	rx = 0;
	ry = 0;
	if ((x || y) && x >= 0 && x < 1000 && y >= 0 && y < 800 && e->enter)
	{
		if (ft_strcmp(e->c, "j") == 0)
		{
			rx = (double)x;
			ry = (double)y;
			e->change->ch_cre = (rx - 500) / 800;
			e->change->ch_cim = (ry - 400) / 800;
		}
		if (ft_strcmp(e->c, "m") == 0)
		{
			rx = (double)x;
			ry = (double)y;
			e->change->ch_mvx = (rx - 500) / 800;
			e->change->ch_mvy = (ry - 400) / 800;
		}
		ft_replaceimg(e);
	}
	return (0);
}
